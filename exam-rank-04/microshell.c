#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define SIDE_OUT 0
#define SIDE_IN 1
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct	s_list
{
	int	type;
	int	pipes[2];
	int	length;
	char	**cmds;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int	ft_strlen(const char *str)
{
	int	count = 0;

	while (str[count])
		count++;
	return (count);
}

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putendl(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}

void	ft_putstr_2d(char **str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putendl(str[i], fd);
		i++;
	}
}

int	show_error(const char *str)
{
	write(STDERR, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

int	error_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i = 0;

	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!cpy)
		error_fatal();
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

int	add_arg(t_list *cmd, char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (cmd->length + 2));
	if (!tmp)
		return (error_fatal());
	while (i < cmd->length)
	{
		tmp[i] = cmd->cmds[i];
		i++;
	}
	if (cmd->length > 0)
		free(cmd->cmds);
	cmd->cmds = tmp;
	cmd->cmds[i++] = ft_strdup(str);
	cmd->cmds[i] = 0;
	cmd->length++;
	return (EXIT_SUCCESS);
}

int	list_push(t_list **cmds, char *str)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (error_fatal());
	new->type = TYPE_END;
	new->length = 0;
	new->next = NULL;
	new->prev = NULL;
	new->cmds = NULL;
	if (*cmds)
	{
		new->prev = (*cmds);
		(*cmds)->next = new;
	}
	(*cmds) = new;
	return (add_arg(new, str));
}

int	parse_arg(t_list **cmds, char *str)
{
	int	is_break;

	is_break = (strcmp(str, ";") == 0);
	if (is_break && (!(*cmds)))
		return (EXIT_SUCCESS);
	else if (!is_break && (!(*cmds) || (*cmds)->type > TYPE_END))
		return (list_push(cmds, str));
	else if (!strcmp(str, "|"))
		(*cmds)->type = TYPE_PIPE;
	else if (!strcmp(str, ";"))
		(*cmds)->type = TYPE_BREAK;
	else
		return(add_arg((*cmds), str));
	return (EXIT_SUCCESS);
}

void	list_rewind(t_list **cmds)
{
	while ((*cmds) && (*cmds)->prev)
		(*cmds) = (*cmds)->prev;
}

int	list_clear(t_list **cmds)
{
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = NULL;
	list_rewind(cmds);
	while ((*cmds))
	{
		tmp = (*cmds)->next;
		i = 0;
		while ((*cmds)->cmds[i])
		{
			free((*cmds)->cmds[i]);
			i++;
		}
		free((*cmds)->cmds);
		free((*cmds));
		(*cmds) = tmp;
	}
	(*cmds) = NULL;
	return (EXIT_SUCCESS);
}

int	exec_cmd(t_list *cmd, char **env)
{
	int	status;
	int	pipe_open;
	int	ret;
	pid_t	pid;

	status = 0;
	pipe_open = 0;
	ret = EXIT_FAILURE;
	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (error_fatal());
	}
	pid = fork();
	if (pid < 0)
		return (error_fatal());
	else if (pid == 0)
	{
		if (pipe_open)
		{
			if ((cmd->type == TYPE_PIPE)
				&& (dup2(cmd->pipes[SIDE_IN], STDOUT) < 0))
				return (error_fatal());
			if ((cmd->prev && cmd->prev->type == TYPE_PIPE)
				&& (dup2(cmd->prev->pipes[SIDE_OUT], STDIN) < 0))
				return (error_fatal());
		}
		if ((ret = execve(cmd->cmds[0], cmd->cmds, env)) < 0)
		{
			show_error("error: cannot execute ");
			show_error(cmd->cmds[0]);
			show_error("\n");
			list_clear(&cmd);
		}
		exit (ret);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->pipes[SIDE_IN]);
			if (!cmd->next || cmd->type == TYPE_BREAK)
				close(cmd->pipes[SIDE_OUT]);
			if (cmd->prev && cmd->prev->type == TYPE_PIPE)
				close(cmd->prev->pipes[SIDE_OUT]);
		}
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int	exec_cmds(t_list **cmds, char **env)
{
	t_list	*crt;
	int		ret;

	ret = EXIT_SUCCESS;
	crt = NULL;
	list_rewind(cmds);
	while ((*cmds))
	{
		crt = (*cmds);
		if (!strcmp(crt->cmds[0], "cd"))
		{
			if (crt->length != 2)
			{
				show_error("error: cd: bad arguments\n");
				ret = EXIT_FAILURE;
			}
			else if (chdir(crt->cmds[1]))
			{
				show_error("error: cd: cannot change directory to ");
				show_error(crt->cmds[1]);
				show_error("\n");
				ret = EXIT_FAILURE;
			}
		}
		else
			ret = exec_cmd(crt, env);
		if (!(*cmds)->next)
			break;
		(*cmds) = (*cmds)->next;
	}
	return (ret);
}

int main(int argc, char **argv, char **env)
{
	t_list	*cmds;
	int		ret;
	int		i;

	cmds = NULL;
	(void)argc;
	i = 1;
	ret = EXIT_SUCCESS;
	while (argv[i])
		parse_arg(&cmds, argv[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, env);
	list_clear(&cmds);
	return (ret);
}
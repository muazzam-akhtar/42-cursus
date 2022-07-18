/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:25 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 18:55:25 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"

# define GRI1 "asset/gri1.xpm"
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define COLLECT "asset/collect.xpm"
# define EXIT_PATH "asset/exit.xpm"
# define EXIT_PATH1 "asset/exit_win.xpm"
# define SKY "asset/night.xpm"
# define BRICK "asset/brick.xpm"
# define CRATE "asset/Crate.xpm"
# define GRASS "asset/grass.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		moves;
	int		width;
	int		height;
	int		x;
	int		y;
	int		wall;
	int		free_sp;
	int		spawn;
	int		exit;
	int		collectible;
	int		area;
	int		rows;
	int		columns;
	char	*map;
	int		i;
	int		collected_tokens;
	int		x_exit;
	int		y_exit;
}				t_data;

typedef struct s_dead
{
	int	i;
	int	flags;
	int	timer;
}				t_dead;

void	ft_init(t_data *vars);
int		file_check(char **arg);
char	*ft_append(char *str, char *buffer);
char	*ft_reading(int fd);
char	*map_work(int fd, t_data *info);
void	player_locator(t_data *vars);
void	put_image_exit(t_data *vars);
void	departure(t_data *vars);
void	movement_up(t_data *vars, int count);
void	movement_down(t_data *vars, int count);
void	movement_right(t_data *vars);
void	movement_left(t_data *vars);
int		go_up(t_data *vars);
int		go_down(t_data *vars);
int		go_right(t_data *vars);
int		go_left(t_data *vars);
void	player_up_image(t_data *vars);
void	player_down_image(t_data *vars);
void	player_right_image(t_data *vars);
void	player_left_image(t_data *vars);
void	open_exit(t_data *vars);
void	map_init(t_data *vars);
void	grass(t_data *vars);
void	print_moves(t_data *vars);

#endif
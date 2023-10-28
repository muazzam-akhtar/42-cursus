#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef struct	s_clients
{
	int	id;
	char	msg[119990];
}				t_clients;

t_clients	clients[1024];
int			fdMax = 0, idNext = 0;
char		bufferWrite[1200000], bufferRead[1200000];
fd_set		readfds, writefds, active;

void	printError(char *str)
{
	if (str)
		write(2, str, strlen(str));
	else
		write(2, "Fatal error", strlen("Fatal error"));
	write(2, "\n", 1);
	exit(1);
}

void	sendAll(int not)
{
	for (int i = 0; i <= fdMax; i++)
		if (FD_ISSET(i, &writefds) && i != not)
			send(i, bufferWrite, strlen(bufferWrite), 0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		printError("Wrong number of arguments");
	int	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0)
		printError(NULL);
	/* Initialising Client Structure and active variable*/
	FD_ZERO(&active);
	bzero(&clients, sizeof(clients));
	fdMax = sock_fd;
	FD_SET(sock_fd, &active);

	/* Initialising Server Address*/
	struct sockaddr_in	server_addr;
	socklen_t			len = 0;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(2130706433);
	server_addr.sin_port = htons(atoi(av[1]));
	if (bind(sock_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
		printError(NULL);
	if (listen(sock_fd, 10) < 0)
		printError(NULL);
	while (1)
	{
		readfds = writefds = active;
		if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0)
			continue;
		for (int fdI = 0; fdI <= fdMax; fdI++)
		{
			if (FD_ISSET(fdI, &readfds) && fdI == sock_fd)
			{
				int	connfd = accept(sock_fd, (struct sockaddr *)&server_addr, &len);
				if (connfd < 0)
					continue;
				clients[connfd].id = idNext++;
				fdMax = connfd > fdMax ? connfd : fdMax;
				FD_SET(connfd, &active);
				sprintf(bufferWrite, "server: client %d just arrived\n", clients[connfd].id);
				sendAll(connfd);
				break;
			}
			if (FD_ISSET(fdI, &readfds) && fdI != sock_fd)
			{
				int	res = recv(fdI, bufferRead, 119990, 0);
				if (res <= 0)
				{
					sprintf(bufferWrite, "server: client %d just left\n", clients[fdI].id);
					sendAll(fdI);
					FD_CLR(fdI, &active);
					close(fdI);
					break;
				}
				else
				{
					for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++)
					{
						clients[fdI].msg[j] = bufferRead[i];
						if (clients[fdI].msg[j] == '\n')
						{
							clients[fdI].msg[j] = 0;
							sprintf(bufferWrite, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
							sendAll(fdI);
							bzero(&clients[fdI].msg, strlen(clients[fdI].msg));
							j = -1;
						}
					}
					break;
				}
			}
		}
	}
	return (0);
}
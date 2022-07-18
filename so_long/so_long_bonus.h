/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:56:25 by makhtar           #+#    #+#             */
/*   Updated: 2021/12/15 17:14:15 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "minilibx/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"

# define GRI1 "asset/gri1.xpm"
# define GRI2 "asset/gri2.xpm"
# define GRI3 "asset/gri3.xpm"
# define GRI4 "asset/gri4.xpm"
# define GRI5 "asset/gri5.xpm"
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define COLLECT "asset/collect.xpm"
# define GRA1 "asset/gra1.xpm"
# define GRA2 "asset/gra2.xpm"
# define GRA3 "asset/gra3.xpm"
# define GRA4 "asset/gra4.xpm"
# define GRA5 "asset/gra5.xpm"
# define GRA6 "asset/gra6.xpm"
# define GRA7 "asset/gra7.xpm"
# define GRA8 "asset/gra8.xpm"
# define GRA9 "asset/gra9.xpm"
# define GRA10 "asset/gra10.xpm"
# define EXIT_PATH "asset/exit.xpm"
# define EXIT_PATH1 "asset/exit_win.xpm"
# define SMOKE1 "asset/s1.xpm"
# define SMOKE2 "asset/s2.xpm"
# define SMOKE3 "asset/s3.xpm"
# define SMOKE4 "asset/s4.xpm"
# define SMOKE5 "asset/s5.xpm"
# define SMOKE6 "asset/s6.xpm"
# define SMOKE7 "asset/s7.xpm"
# define SMOKE8 "asset/s8.xpm"
# define PA1 "asset/pa1.xpm"
# define PA2 "asset/pa2.xpm"
# define PA3 "asset/pa3.xpm"
# define PA4 "asset/pa4.xpm"
# define PA5 "asset/pa5.xpm"
# define PA6 "asset/pa6.xpm"
# define PA7 "asset/pa7.xpm"
# define PA8 "asset/pa8.xpm"
# define PA9 "asset/pa9.xpm"
# define PA10 "asset/pa10.xpm"
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
	int		collect_triggered;
	int		wizards;
	int		*x_wizards;
	int		*y_wizards;
	int		*i_wizards;
	int		left_triggered;
	int		right_triggered;
	int		death_triggered;
	int		killer;
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
int		killer_locator(t_data *vars);
void	collect_flag(t_data *vars);
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
void	ft_allocate(t_data *vars);
void	print_moves(t_data *vars);
void	player_idle_sprite(t_data *vars);
void	collect_sprite(t_data *vars);
void	wizard_movement(t_data *vars);
int		dead_sprite(t_data *vars);

#endif
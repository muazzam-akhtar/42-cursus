#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_zone
{
	int	width;
	int	height;
	char	background;
}				t_zone;

typedef struct	s_shape
{
	char	type;
	float	x;
	float	y;
	float	height;
	float	width;
	char	color;
}				t_shape;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

int	str_error(char *str, int ret)
{
	ft_putendl(str);
	return (ret);
}

int	clear_all(FILE *file, char *drawing)
{
	fclose(file);
	if (drawing)
		free(drawing);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_zone(t_zone *zone)
{
	if (zone->width > 0 && zone->width < 300)
	{
		if (zone->height > 0 && zone->height < 300)
			return (1);
	}
	return (0);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int	scan_ret;

	scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background);
	if (scan_ret != 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	if (scan_ret == -1)
		return (0);
	return (1);
}

char	*paint_background(t_zone *zone)
{
	char	*drawing;
	int		i;

	i = 0;
	drawing = malloc(sizeof(char) * (zone->width * zone->height + 1));
	if (!drawing)
		return (NULL);
	while (i < (zone->width * zone->height))
	{
		drawing[i] = zone->background;
		i++;
	}
	// drawing[i] = 0;
	return (drawing);
}

int	check_shape(t_shape *shape)
{
	if (shape->width > 0.00000000 && shape->height > 0.00000000)
	{
		if (shape->type == 'r' || shape->type == 'R')
			return (1);
	}
	return (0);
}

int	in_rectangle(float x, float y, t_shape *shape)
{
	if ((x < shape->x) || (shape->x + shape->width < x) || (y < shape->y) || (shape->height + shape->y < y))
		return (0);
	if ((x - shape->x < 1.00000000) || ((shape->x + shape->width) - x < 1.00000000) || (y - shape->y < 1.00000000) || (shape->y + shape->height - y < 1.00000000))
		return (2);
	return (1);
}

void	draw_shape(char **drawing, t_zone *zone, t_shape *shape)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			ret = in_rectangle(j, i, shape);
			if ((shape->type == 'r' && ret == 2) || (shape->type == 'R' && ret))
				(*drawing)[(i * zone->width) + j] = shape->color;
			j++;
		}
		i++;
	}
}

int	draw_shapes(char **drawing, t_zone *zone, FILE *file)
{
	t_shape	shape;
	int		scan_ret;

	while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.width, &shape.height, &shape.color)) == 6)
	{
		if (!check_shape(&shape))
			return (0);
		draw_shape(drawing, zone, &shape);
	}
	if (scan_ret != -1)
		return (0);
	return (1);
}

void	draw_drawing(char *drawing, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		ft_putchar('\n');
		i++;
	}
}

void	ft_init(t_zone *zone)
{
	zone->background = 0;
	zone->height = 0;
	zone->width = 0;
}

int main(int argc, char **argv)
{
	t_zone	zone;
	FILE	*file;
	char	*drawing;

	ft_init(&zone);
	if (argc == 2)
	{
		if (!(file = fopen(argv[1], "r")))
			return (str_error("Error: Operation file Corrupted", 1));
		if (!get_zone(file, &zone))
			return (clear_all(file, NULL) && str_error("Error: Operation file Corrupted", 1));
		if (!(drawing = paint_background(&zone)))
			return (clear_all(file, NULL) && str_error("Error: Malloc Failed", 1));
		if (!draw_shapes(&drawing, &zone, file))
			return (clear_all(file, drawing) && str_error("Error: Operation file Corrupted", 1));
		draw_drawing(drawing, &zone);
		clear_all(file, drawing);
	}
	else
		ft_putendl("Error: argument");
	return (0);
}
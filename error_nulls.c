/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_nulls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:10:13 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 16:10:17 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_source *src, int code)
{
	src->j = 0;
	if (src->map)
	{
		while (src->j <= src->max_y)
		{
			free(src->map[src->j]);
			src->j++;
		}
		free(src->map);
	}
	exit(code);
}

void	ft_free_mass(char **matrix)
{
	int	j;

	j = 0;
	while (matrix[j] != NULL)
		j++;
	while (j >= 0)
	{
		free(matrix[j]);
		matrix[j] = NULL;
		j--;
	}
}

void	put_neitral(t_source *src)
{
	src->cou_widf = 0;
	src->cou_lenf = 0;
	src->j = 0;
	src->i = 0;
	src->cou_step = 0;
	src->coin = mlx_xpm_file_to_image(src->mlx, "./pics/coin.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->p_r = mlx_xpm_file_to_image(src->mlx, "./pics/put_right.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->exit = mlx_xpm_file_to_image(src->mlx, "./pics/exit.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->wall = mlx_xpm_file_to_image(src->mlx, "./pics/wall.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->flor = mlx_xpm_file_to_image(src->mlx, "./pics/back.xpm",
			&src->cou_widf, &src->cou_lenf);
}

void	ft_error(int err)
{
	if (err == 1)
		printf("Error : map not found\n");
	else if (err == 2)
		printf("Error : wrong number of arguments\n");
	else if (err == 3)
		printf("Error : wrong type of file\n");
	else if (err == 4)
		printf("Error : open failed on input file\n");
	else if (err == 5)
		printf("Error : wrong map\n");
	exit (0);
}

int	cou_lin(char *str, t_source *src)
{
	char	s;
	int		fd;

	src->cou_plyr = 0;
	src->max_y = 0;
	src->max_x = 0;
	fd = open (str, O_RDONLY);
	if (fd == -1)
		ft_error(4);
	while (read(fd, &s, 1) == 1)
	{
		if (s == '\n')
			src->max_y++;
		if (src->max_y == 0 && s != '\n')
			src->max_x++;
	}
	if (src->max_x == 0)
		ft_error(5);
	close(fd);
	return (++src->max_y);
}

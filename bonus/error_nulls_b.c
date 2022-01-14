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

#include "so_long_b.h"

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
	src->coin = mlx_xpm_file_to_image(src->mlx, "./pics/coin_2.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->plyr_r = mlx_xpm_file_to_image(src->mlx, "./pics/put_r.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->plyr_l = mlx_xpm_file_to_image(src->mlx, "./pics/put_l.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->plyr_u = mlx_xpm_file_to_image(src->mlx, "./pics/put_u.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->plyr_d = mlx_xpm_file_to_image(src->mlx, "./pics/put_d.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->enemy_0 = mlx_xpm_file_to_image(src->mlx, "./pics/enemy_0.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->enemy_1 = mlx_xpm_file_to_image(src->mlx, "./pics/enemy_1.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->exit = mlx_xpm_file_to_image(src->mlx, "./pics/exit_2.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->wall = mlx_xpm_file_to_image(src->mlx, "./pics/wall_2.xpm",
			&src->cou_widf, &src->cou_lenf);
	src->flor = mlx_xpm_file_to_image(src->mlx, "./pics/back_3.xpm",
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
	src->enmy_x = 0;
	src->enmy_y = 0;
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

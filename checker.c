/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:10:01 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 16:10:04 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_if_map_good(t_source *src, char **map, int i, int j)
{
	if (map[0][j] != '1' || map[src->max_y - 1][j] != '1' ||
		map[i][0] != '1' || map[i][src->max_x - 1] != '1')
		if (map[i][j] != '\n' && map[i][j] != '\0')
			return (1);
	if (map[i][j] == 'E')
		src->cou_exit++;
	else if (map[i][j] == 'P')
		src->cou_plyr++;
	else if (map[i][j] == 'C')
		src->cou_c++;
	else if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != '\0' && map[i][++j] != '\n')
		return (1);
	return (0);
}

int	ft_check_map(t_source *src, char **map, int i, int j)
{
	src->cou_c = 0;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			if (ft_if_map_good(src, map, i, j))
				return (1);
		}
		if ((j != src->max_x || src->max_x < 3) && i != src->max_y)
			return (1);
	}
	if (src->cou_exit < 1 || src->cou_plyr != 1 || src->cou_c < 1
		|| src->max_y < 4 || src->max_x < 4)
		return (1);
	return (0);
}

void	ft_checker(int argc, char **argv, t_source *src, int i)
{
	if (argc < 2)
		ft_error(1);
	else if (argc > 2)
		ft_error(2);
	else
	{
		while (argv[1][i] != '\0')
			i++;
		if (ft_strncmp(&(argv[1][i - 4]), ".ber", 4))
			ft_error(3);
	}
	i = -1;
	src->map = (char **)malloc(sizeof(char *) * ((cou_lin(argv[1], src) + 1)));
	src->fd = open (argv[1], O_RDONLY);
	if (src->fd < 0)
		ft_error(4);
	while (++i <= src->max_y)
		src->map[i] = get_next_line(src->fd);
	src->map[i - 1] = NULL;
	if (ft_check_map(src, src->map, -1, -1))
	{
		ft_free_mass(src->map);
		ft_error(5);
	}
	close(src->fd);
}

void	put_pik_p(t_source *src, int x, int y)
{
	mlx_put_image_to_window(src->mlx, src->win, src->p_r, \
					x * src->size, y * src->size);
	src->plyr_x = x;
	src->plyr_y = y;
}

void	put_pik_wnd(t_source *src, int x, int y)
{
	while (src->map[++y])
	{
		x = -1;
		while (src->map[y][++x] != '\n' && src->map[y][x] != '\0')
		{
			if (src->map[y][x] == '1')
				mlx_put_image_to_window(src->mlx, src->win, src->wall, \
					x * src->size, y * src->size);
			if (src->map[y][x] != '1')
				mlx_put_image_to_window(src->mlx, src->win, src->flor, \
					x * src->size, y * src->size);
			if (src->map[y][x] == 'C')
				mlx_put_image_to_window(src->mlx, src->win, src->coin, \
					x * src->size, y * src->size);
			if (src->map[y][x] == 'P')
				put_pik_p(src, x, y);
			if (src->map[y][x] == 'E')
				mlx_put_image_to_window(src->mlx, src->win, src->exit, \
					x * src->size, y * src->size);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:10:29 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 16:10:32 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_c(int x, int y, t_source *src)
{
	src->map[src->plyr_y][src->plyr_x] = '0';
	mlx_put_image_to_window(src->mlx, src->win, src->flor,
		src->plyr_x * src->size, src->plyr_y * src->size);
	src->cou_c--;
	src->plyr_x += x;
	src->plyr_y += y;
	src->map[src->plyr_y][src->plyr_x] = 'P';
	mlx_put_image_to_window(src->mlx, src->win, src->flor,
		src->plyr_x * src->size, src->plyr_y * src->size);
	mlx_put_image_to_window(src->mlx, src->win, src->p_r,
		src->plyr_x * src->size, src->plyr_y * src->size);
}

void	move(int x, int y, t_source *src)
{
	if (src->map[src->plyr_y + y][src->plyr_x + x] != '1')
	{
		if (src->map[src->plyr_y + y][src->plyr_x + x] == '0')
		{
			src->map[src->plyr_y][src->plyr_x] = '0';
			mlx_put_image_to_window(src->mlx, src->win, src->flor,
				src->plyr_x * src->size, src->plyr_y * src->size);
			src->plyr_x += x;
			src->plyr_y += y;
			src->map[src->plyr_y][src->plyr_x] = 'P';
			mlx_put_image_to_window(src->mlx, src->win, src->p_r,
				src->plyr_x * src->size, src->plyr_y * src->size);
		}
		else if (src->map[src->plyr_y + y][src->plyr_x + x] == 'C')
			move_c(x, y, src);
		else if (src->map[src->plyr_y + y][src->plyr_x + x] == 'E' &&
				src->cou_c == 0)
		{
			mlx_put_image_to_window(src->mlx, src->win, src->flor,
				src->plyr_x * src->size, src->plyr_y * src->size);
			printf("You are the king of the dirty room!\n");
			close_program(src, 0);
		}
	}
	printf("Step %d\n", ++src->cou_step);
}

int	key_hook(int code, t_source *src)
{
	if (code == 53)
		close_program(src, 0);
	else if (code == 13)
		move(0, -1, src);
	else if (code == 0)
		move(-1, 0, src);
	else if (code == 1)
		move(0, 1, src);
	else if (code == 2)
		move(1, 0, src);
	return (0);
}

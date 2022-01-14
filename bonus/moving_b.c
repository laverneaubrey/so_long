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

#include "so_long_b.h"

void	move_pic_c(int x, int y, t_source *src, void *pic)
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
	mlx_put_image_to_window(src->mlx, src->win, pic,
		src->plyr_x * src->size, src->plyr_y * src->size);
}

void	move_pic(int x, int y, t_source *src, void *pic)
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
			mlx_put_image_to_window(src->mlx, src->win, pic,
				src->plyr_x * src->size, src->plyr_y * src->size);
		}
		else if (src->map[src->plyr_y + y][src->plyr_x + x] == 'C')
			move_pic_c(x, y, src, pic);
		else if (src->cou_c == 0 && \
		src->map[src->plyr_y + y][src->plyr_x + x] == 'E')
		{
			mlx_put_image_to_window(src->mlx, src->win, src->flor,
				src->plyr_x * src->size, src->plyr_y * src->size);
			printf("You are the king of the dirty room!\n");
			close_program(src, 0);
		}
	}
	++src->cou_step;
}

void	move_pic_en(int x, int y, t_source *src, void *pic)
{
	if (src->map[src->enmy_y + y][src->enmy_x + x] != '1' &&
		src->map[src->enmy_y + y][src->enmy_x + x] != 'E' &&
			src->map[src->enmy_y + y][src->enmy_x + x] != 'C')
	{
		if (src->map[src->enmy_y + y][src->enmy_x + x] == '0')
		{
			src->map[src->enmy_y][src->enmy_x] = '0';
			mlx_put_image_to_window(src->mlx, src->win, src->flor,
				src->enmy_x * src->size, src->enmy_y * src->size);
			src->enmy_x += x;
			src->enmy_y += y;
			src->map[src->enmy_y][src->enmy_x] = 'W';
			mlx_put_image_to_window(src->mlx, src->win, pic,
				src->enmy_x * src->size, src->enmy_y * src->size);
		}
		else if (src->map[src->enmy_y + y][src->enmy_x + x] == 'P')
		{
			printf("Navalniy wins!\n");
			close_program(src, 0);
		}
	}
	else
		move_pic_en(-x, -y, src, src->enemy_0);
	output_counter(src);
}

void	move_enemy(t_source *src)
{
	if (src->max_x / 2 > src->plyr_x)
	{
		if (src->cou_step % 2)
			move_pic_en(-1, 0, src, src->enemy_0);
		else
			move_pic_en(-1, 0, src, src->enemy_1);
	}
	else
	{
		if (src->cou_step % 2)
			move_pic_en(1, 0, src, src->enemy_0);
		else
			move_pic_en(1, 0, src, src->enemy_1);
	}
	if (src->max_y / 2 > src->plyr_y)
		move_pic_en(0, -1, src, src->enemy_0);
	else
	{
		if (src->cou_step % 2)
			move_pic_en(0, 1, src, src->enemy_0);
		else
			move_pic_en(0, 1, src, src->enemy_1);
	}
}

int	key_hook(int code, t_source *src)
{
	if (code == 53)
		close_program(src, 0);
	else if (code == 13)
	{
		move_enemy(src);
		move_pic(0, -1, src, src->plyr_u);
	}
	else if (code == 0)
	{
		move_enemy(src);
		move_pic(-1, 0, src, src->plyr_l);
	}
	else if (code == 1)
	{
		move_enemy(src);
		move_pic(0, 1, src, src->plyr_d);
	}
	else if (code == 2)
	{
		move_enemy(src);
		move_pic(1, 0, src, src->plyr_r);
	}
	return (0);
}

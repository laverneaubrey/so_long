/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:59:40 by vchange           #+#    #+#             */
/*   Updated: 2021/10/16 19:28:01 by vchange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_b.h"

void	output_counter(t_source *src)
{
	char	*step;
	char	*step2;
	char	*step3;

	step = ft_itoa(src->cou_step);
	step3 = malloc((sizeof(char)) * 6);
	step3[0] = 'S';
	step3[1] = 't';
	step3[2] = 'e';
	step3[3] = 'p';
	step3[4] = ':';
	step2 = ft_strjoin(step3, step);
	mlx_put_image_to_window(src->mlx, src->win, src->wall, 0, 0);
	mlx_put_image_to_window(src->mlx, src->win, src->wall, 64, 0);
	mlx_string_put(src->mlx, src->win, 17, 32, 999999, step2);
	free(step2);
}

int	main(int argc, char **argv)
{
	t_source	src;

	src.cou_c = 0;
	src.cou_exit = 0;
	src.size = 65;
	ft_checker(argc, argv, &src, 0);
	src.mlx = mlx_init();
	src.win = mlx_new_window(src.mlx, src.max_x * src.size,
			src.max_y * src.size, "Dirty ROOM!");
	put_neitral(&src);
	put_pik_wnd(&src, -1, -1);
	mlx_hook(src.win, 17, 0, close_program, &src);
	mlx_key_hook(src.win, key_hook, &src);
	mlx_loop(src.mlx);
}

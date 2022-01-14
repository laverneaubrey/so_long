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

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_source	src;

	src.cou_exit = 0;
	src.size = 52;
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

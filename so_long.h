/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:44:27 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 18:44:33 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./qmlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_source{
	void	*mlx;
	void	*win;
	char	**map;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*p_r;
	void	*flor;
	int		plyr_x;
	int		plyr_y;
	int		cou_step;
	int		size;
	int		fd;
	int		max_y;
	int		max_x;
	int		cou_exit;
	int		cou_plyr;
	int		cou_c;
	int		cou_widf;
	int		cou_lenf;
	int		i;
	int		j;
}				t_source;

int		close_program(t_source *src, int code);
void	ft_free_mass(char **matrix);
void	put_neitral(t_source *src);
void	ft_error(int err);
int		cou_lin(char *str, t_source *src);
int		ft_check_map(t_source *src, char **map, int i, int j);
void	ft_checker(int argc, char **argv, t_source *src, int i);
void	put_pik_wnd(t_source *src, int x, int y);
void	move(int x, int y, t_source *src);
int		key_hook(int code, t_source *src);
int		ft_if_map_good(t_source *src, char **map, int i, int j);
void	put_pik_p(t_source *src, int x, int y);
void	move_c(int x, int y, t_source *src);

#endif

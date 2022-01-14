/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:47:28 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 18:48:41 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*buf_strjoin(char *s1, char const *s2, size_t	n);
void	*ft_mem(char *dst, const void *src, size_t	n);
size_t	ft_strlen(const char *s);
int		fun_chek(char *s);
int		buf_creater(char **buf, int fd);

#endif

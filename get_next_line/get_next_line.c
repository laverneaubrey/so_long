/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:47:14 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 18:47:17 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	buf_creater(char **buf, int fd)
{
	int	i;

	i = 0;
	if (*buf && (*buf)[0] == '\0')
	{
		i = read(fd, *buf, BUFFER_SIZE);
		if (i != 0)
			(*buf)[i] = '\0';
	}
	else if (!(*buf))
	{
		if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0)))
			return (1);
		*buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (!(*buf))
			return (1);
		i = read(fd, *buf, BUFFER_SIZE);
		(*buf)[i] = '\0';
	}
	return (0);
}

int	fun_chek(char *s)
{
	int	i;

	i = 1;
	if (!s)
		return (0);
	while (s[i - 1])
	{
		if (s[i - 1] == '\n')
			return (i);
		i++;
	}
	return (i - 1);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			i;

	line = NULL;
	if (buf_creater(&buf, fd))
		return (NULL);
	while (fun_chek(buf))
	{
		i = fun_chek(buf);
		line = buf_strjoin(line, buf, i);
		buf = ft_mem(buf, &(buf[i]), ft_strlen(&(buf[i])));
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
		i = read(fd, buf, BUFFER_SIZE);
		if (i != 0)
			buf[i] = '\0';
	}
	if (line)
		return (line);
	free(buf);
	buf = NULL;
	return (NULL);
}

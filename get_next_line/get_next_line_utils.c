/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:48:10 by laubrey           #+#    #+#             */
/*   Updated: 2021/11/12 18:48:13 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_mem(char *dst, const void *src, size_t	n)
{
	size_t	i;

	i = 0;
	while ((n > i) && (dst || src))
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*buf_strjoin(char *s1, char const *s2, size_t	n)
{
	char	*stng;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	if (ft_strlen(s2) > n)
		len2 = n;
	else
		len2 = ft_strlen(s2);
	stng = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(stng))
		return (NULL);
	ft_mem(stng, s1, len1);
	free(s1);
	ft_mem(&stng[len1], s2, len2);
	stng[len1 + len2] = '\0';
	return (stng);
}

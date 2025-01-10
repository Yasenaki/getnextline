/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopires- <jopires-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:33:04 by jopires-          #+#    #+#             */
/*   Updated: 2025/01/10 19:28:40 by jopires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	out = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[x++] = s1[i];
		i++;
	}
	if (ft_strlen(s1) > 1)
		free(s1);
	i = 0;
	while (s2[i])
	{
		out[x++] = s2[i];
		i++;
	}
	out[x] = '\0';
	return (out);
}

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

void	buffer_reset(char *buffer)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (buffer && buffer[x] != '\n' && x < BUFFER_SIZE)
	{
		buffer[x] = '\0';
		x++;
	}
	if (buffer && buffer[x] == '\n')
	{
		buffer[x] = '\0';
		x++;
		while (x < BUFFER_SIZE)
		{
			buffer[y] = buffer[x];
			buffer[x] = '\0';
			x++;
			y++;
		}
	}
}

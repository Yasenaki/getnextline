/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopires- <jopires-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:33:02 by jopires-          #+#    #+#             */
/*   Updated: 2025/01/10 19:25:56 by jopires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	int			bytesread;
	static char	buffer [BUFFER_SIZE +1];

	str = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
			return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		buffer_reset(buffer);
		if (str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
	if (ft_strlen(str) < 1)
		return (NULL);
	return (str);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	line = get_next_line(fd);
	if (line)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}

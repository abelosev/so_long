/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:03:11 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 00:37:28 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ft_get_prevline(int fd, char *prev_line)
{
	char	*buf;
	int		ret;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(prev_line, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		prev_line = ft_strjoin(prev_line, buf);
	}
	free(buf);
	return (prev_line);
}

char	*get_next_line(int fd)
{
	static char	*prev_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	prev_line = ft_get_prevline(fd, prev_line);
	if (!prev_line)
		return (NULL);
	line = ft_get_line(prev_line);
	prev_line = ft_new_prevline(prev_line);
	return (line);
}

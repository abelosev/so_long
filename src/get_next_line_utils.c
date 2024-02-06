/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:31:26 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 00:38:20 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *prev_line, char *buf)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!prev_line)
	{
		prev_line = (char *)malloc(1 * sizeof(char));
		prev_line[0] = '\0';
	}
	if (!prev_line || !buf)
		return (NULL);
	s = malloc(sizeof(char) * ((ft_strlen(prev_line) + ft_strlen(buf)) + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (prev_line)
		while (prev_line[++i] != '\0')
			s[i] = prev_line[i];
	while (buf[j] != '\0')
		s[i++] = buf[j++];
	s[ft_strlen(prev_line) + ft_strlen(buf)] = '\0';
	free(prev_line);
	return (s);
}

char	*ft_get_line(char *prev_line)
{
	int		i;
	char	*s;

	i = 0;
	if (!prev_line[i])
		return (NULL);
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
	{
		s[i] = prev_line[i];
		i++;
	}
	if (prev_line[i] == '\n')
	{
		s[i] = prev_line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_new_prevline(char *prev_line)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (prev_line[i] && prev_line[i] != '\n')
		i++;
	if (!prev_line[i])
	{
		free(prev_line);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(prev_line) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (prev_line[i])
		s[j++] = prev_line[i++];
	s[j] = '\0';
	free(prev_line);
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:32:52 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/06 10:23:14 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	line_count(int fd)
{
	char	*line;
	int		line_nbr;

	line = get_next_line(fd);
	line_nbr = 0;
	while (line != NULL)
	{
		line_nbr++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_nbr);
}

char	**get_tab(int fd, int line_nbr)
{
	char	**tab;
	int		i;
	int		k;

	i = 0;
	tab = malloc(sizeof(char *) * (line_nbr + 1));
	if (!tab)
		exit(EXIT_FAILURE);
	while (i <= line_nbr)
	{
		k = 0;
		tab[i] = get_next_line(fd);
		if (tab[i] == NULL)
			break ;
		while (tab[i][k])
		{
			if (tab[i][k] == '\n')
				tab[i][k] = '\0';
			k++;
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	map_parsing(t_mlx_data *data)
{
	int	i;
	int	k;

	data->map.collect_nb = 0;
	i = 0;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k] != '\0')
		{
			if (data->tab[i][k] == 'P')
			{
				data->map.p_y = i;
				data->map.p_x = k;
			}
			else if (data->tab[i][k] == 'C')
				data->map.collect_nb++;
			k++;
		}
		i++;
	}
}

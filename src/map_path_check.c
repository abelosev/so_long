/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:03:34 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/06 10:31:36 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	get_tab_path1(t_mlx_data *data, int fd, int line_nbr)
{
	int		i;
	int		k;

	i = 0;
	data->tab_path1 = malloc(sizeof(char *) * (line_nbr + 1));
	if (!data->tab_path1)
		exit(EXIT_FAILURE);
	while (i <= line_nbr)
	{
		k = 0;
		data->tab_path1[i] = get_next_line(fd);
		if (data->tab_path1[i] == NULL)
			break ;
		while (data->tab_path1[i][k])
		{
			if (data->tab_path1[i][k] == '\n')
				data->tab_path1[i][k] = '\0';
			k++;
		}
		i++;
	}
	data->tab_path1[i] = NULL;
}

void	fill_outils(t_mlx_data *data, int y, int x)
{
	fill(data, y, x - 1);
	fill(data, y, x + 1);
	fill(data, y - 1, x);
	fill(data, y + 1, x);
}

int	fill(t_mlx_data *data, int y, int x)
{
	if (data->map.score != data->map.collect_nb)
	{
		if (x < 0 || y < 0 || x >= data->map.line_len || y >= data->map.line_nb)
			return (0);
		if (data->tab_path1[y][x] == 'F' || data->tab_path1[y][x] == '1'
				|| data->tab_path1[y][x] == 'E')
			return (0);
		else if (data->tab_path1[y][x] == 'C')
			data->map.score++;
		data->tab_path1[y][x] = 'F';
	}
	else if (data->map.score == data->map.collect_nb)
	{
		if (x < 0 || y < 0 || x >= data->map.line_len || y >= data->map.line_nb)
			return (0);
		if (data->tab_path1[y][x] == '1' || data->tab_path1[y][x] == 'X')
			return (0);
		else if (data->tab_path1[y][x] == 'E')
			data->map.exit_path++;
		data->tab_path1[y][x] = 'X';
	}
	fill_outils(data, y, x);
	return (1);
}

void	flood_fill(t_mlx_data *data)
{
	if (fill(data, data->map.p_y, data->map.p_x) == 0
		|| data->map.score != data->map.collect_nb
		|| data->map.exit_path == 0)
	{
		ft_putstr("Error : invalid path\n");
		free_tab(data->tab_path1);
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
	else
		free_tab(data->tab_path1);
}

void	path_check(t_mlx_data *data, char **av)
{
	int			fd;
	int			line_nbr;

	fd = open(av[1], O_RDONLY);
	error_handler(fd);
	line_nbr = line_count(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	error_handler(fd);
	get_tab_path1(data, fd, line_nbr);
	close(fd);
	map_parsing(data);
	flood_fill(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:32:34 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/06 10:24:23 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	extra_elements(t_mlx_data *data)
{
	int	i;
	int	k;

	i = 0;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k] != '\0')
		{
			if (!(data->tab[i][k] == '0' || data->tab[i][k] == '1' ||
						data->tab[i][k] == 'C' ||
						data->tab[i][k] == 'E' ||
						data->tab[i][k] == 'P'))
			{
				ft_putstr("The map contains inappropriate characters\n");
				free_tab(data->tab);
				exit(EXIT_FAILURE);
			}
			k++;
		}
		i++;
	}
}

void	map_size_count(t_mlx_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data->tab[0][k])
		k++;
	data->map.line_len = k;
	while (data->tab[i])
		i++;
	data->map.line_nb = i;
}

void	rectangular_check(t_mlx_data *data)
{
	int	i;
	int	k;

	i = 0;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k])
			k++;
		if (k != data->map.line_len)
		{
			ft_putstr("Error : not rectangular\n");
			free_tab(data->tab);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	free_spaces_check(t_mlx_data *data)
{
	int	i;
	int	k;
	int	nb_0;

	i = 0;
	nb_0 = 0;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k])
		{
			if (data->tab[i][k] == '0')
				nb_0++;
			k++;
		}
		i++;
	}
	if (nb_0 == 0)
	{
		ft_putstr("Error: the map doesn't contain free spaces\n");
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
}

void	map_check(t_mlx_data *data)
{
	if (ft_strlen(data->tab[0]) == 0)
	{
		ft_putstr("Error: incorrect map\n");
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
	extra_elements(data);
	data_initiate (data);
	map_size_count(data);
	rectangular_check(data);
	wall_check(data);
	nb_check(data);
	free_spaces_check(data);
}

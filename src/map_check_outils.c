/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:32:18 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/06 10:25:11 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	data_initiate(t_mlx_data *data)
{
	data->map.player_nb = 0;
	data->map.exit_nb = 0;
	data->map.collect_nb = 0;
	data->map.line_len = 0;
	data->map.line_nb = 0;
	data->map.p_x = 0;
	data->map.p_y = 0;
	data->move_nb = 0;
	data->map.score = 0;
	data->map.exit_path = 0;
	data->textures.collect = NULL;
	data->textures.player = NULL;
	data->textures.floor = NULL;
	data->textures.wall = NULL;
	data->textures.exit = NULL;
}

void	nb_analyse(t_mlx_data *data)
{
	if (data->map.exit_nb != 1)
	{
		ft_putstr("Error : the number of exits is not 1\n");
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
	else if (data->map.player_nb != 1)
	{
		ft_putstr("Error : the number of players is not 1\n");
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
	else if (data->map.collect_nb < 1)
	{
		ft_putstr("Error : the number of collectibles is less than 1\n");
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
	else
		return ;
}

void	nb_check(t_mlx_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k])
		{
			if (data->tab[i][k] == 'E')
				data->map.exit_nb++;
			if (data->tab[i][k] == 'P')
				data->map.player_nb++;
			if (data->tab[i][k] == 'C')
				data->map.collect_nb++;
			k++;
		}
		i++;
	}
	nb_analyse(data);
}

void	wall_check_act(t_mlx_data *data, int i, int k)
{
	if (data->tab[i][k] != '1')
	{
		ft_putstr("Error : walls problem\n");
		free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
}

void	wall_check(t_mlx_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < data->map.line_len)
		wall_check_act(data, i, k++);
	k--;
	while (i < data->map.line_nb)
		wall_check_act(data, i++, k);
	i--;
	while (k >= 0)
		wall_check_act(data, i, k--);
	k++;
	while (i >= 0)
		wall_check_act(data, i--, k);
}

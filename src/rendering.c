/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:33:03 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/06 10:26:40 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	put_textures(t_mlx_data *data, int t_width, int t_height)
{
	data->textures.floor = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm", &t_width, &t_height);
	data->textures.player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &t_width, &t_height);
	data->textures.exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &t_width, &t_height);
	data->textures.collect = mlx_xpm_file_to_image(data->mlx,
			"./textures/item.xpm", &t_width, &t_height);
	data->textures.wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &t_width, &t_height);
	if (data->textures.floor == NULL || data->textures.player == NULL
		|| data->textures.exit == NULL || data->textures.collect
		== NULL || data->textures.wall == NULL)
	{
		ft_putstr("Textures are not found\n");
		game_close(data);
	}
}

void	rendering_outils(t_mlx_data *data, int t_width, int t_height, int i, int k)
{
	if (data->tab[i][k] == '0')
		mlx_put_image_to_window (data->mlx, data->win,
			data->textures.floor, k * t_width, i * t_height);
	else if (data->tab[i][k] == 'C')
		mlx_put_image_to_window (data->mlx, data->win,
			data->textures.collect, k * t_width, i * t_height);
	else if (data->tab[i][k] == '1')
		mlx_put_image_to_window (data->mlx, data->win,
			data->textures.wall, k * t_width, i * t_height);
	else if (data->tab[i][k] == 'P')
		mlx_put_image_to_window (data->mlx, data->win,
			data->textures.player, k * t_width, i * t_height);
	else if (data->tab[i][k] == 'E')
		mlx_put_image_to_window (data->mlx, data->win,
			data->textures.exit, k * t_width, i * t_height);
}

void	rendering(t_mlx_data *data, int t_width, int t_height)
{
	int	i;
	int	k;

	i = 0;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k])
		{
			rendering_outils(data, t_width, t_height, i, k);
			k++;
		}
		i++;
	}
}

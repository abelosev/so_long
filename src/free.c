/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:30:53 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 00:39:24 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_tab(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
	{
		free(arr[len]);
		len++;
	}
	free(arr);
}

void	free_textures(t_mlx_data *data)
{
	if (data->textures.collect)
		mlx_destroy_image(data->mlx, data->textures.collect);
	if (data->textures.floor)
		mlx_destroy_image(data->mlx, data->textures.floor);
	if (data->textures.wall)
		mlx_destroy_image(data->mlx, data->textures.wall);
	if (data->textures.player)
		mlx_destroy_image(data->mlx, data->textures.player);
	if (data->textures.exit)
		mlx_destroy_image(data->mlx, data->textures.exit);
}

int	game_close(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_textures(data);
	mlx_destroy_display(data->mlx);
	if (data->tab)
		free_tab(data->tab);
	if (data->mlx)
		free(data->mlx);
	exit(EXIT_SUCCESS);
}

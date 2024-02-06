/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:32:02 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 19:07:58 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	win_null(t_mlx_data *data)
{
	mlx_destroy_display(data->mlx);
	if (data->tab)
		free_tab(data->tab);
	if (data->mlx)
		free(data->mlx);
	exit(EXIT_FAILURE);
}

void	game(t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		if (data->tab)
			free_tab(data->tab);
		exit(EXIT_FAILURE);
	}
	data->w_height = (data->map.line_nb) * THEIGHT;
	data->w_width = (data->map.line_len) * TWIDTH;
	data->win = mlx_new_window (data->mlx, data->w_width,
			data->w_height, "So_long");
	if (data->win == NULL)
		win_null(data);
	map_parsing(data);
	put_textures(data, TWIDTH, THEIGHT);
	rendering(data, TWIDTH, THEIGHT);
	mlx_key_hook(data->win, handle_key, data);
	mlx_hook(data->win, 17, 1L << 0, game_close, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	int			fd;
	int			line_nbr;
	t_mlx_data	data;

	input_handler(ac, av);
	fd = open(av[1], O_RDONLY);
	error_handler(fd);
	line_nbr = line_count(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	error_handler(fd);
	data.tab = get_tab(fd, line_nbr);
	close(fd);
	map_check(&data);
	path_check(&data, av);
	game(&data);
	return (0);
}

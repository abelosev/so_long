/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:29:54 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 19:28:25 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	for_x(t_mlx_data *data, int *i, int *k, int temp)
{
	if (data->tab[*i][temp] == '0')
	{
		data->tab[*i][temp] = 'P';
		data->tab[*i][*k] = '0';
		data->move_nb++;
		moves_announcer(data->move_nb);
	}
	else if (data->tab[*i][temp] == 'C' && data->map.collect_nb != 0)
	{
		data->tab[*i][temp] = 'P';
		data->tab[*i][*k] = '0';
		data->map.collect_nb--;
		data->move_nb++;
		moves_announcer(data->move_nb);
	}
	else if (data->tab[*i][temp] == 'E' && data->map.collect_nb == 0)
	{
		data->tab[*i][*k] = '0';
		data->move_nb++;
		moves_announcer(data->move_nb);
		ft_putstr("You won the game! Congratulations!\n");
		game_close(data);
	}
}

void	for_y(t_mlx_data *data, int *i, int *k, int temp)
{
	if (data->tab[temp][*k] == '0')
	{
		data->tab[temp][*k] = 'P';
		data->tab[*i][*k] = '0';
		data->move_nb++;
		moves_announcer(data->move_nb);
	}
	else if (data->tab[temp][*k] == 'C' && data->map.collect_nb != 0)
	{
		data->tab[temp][*k] = 'P';
		data->tab[*i][*k] = '0';
		data->map.collect_nb--;
		data->move_nb++;
		moves_announcer(data->move_nb);
	}
	else if (data->tab[temp][*k] == 'E' && data->map.collect_nb == 0)
	{
		data->tab[*i][*k] = '0';
		data->move_nb++;
		moves_announcer(data->move_nb);
		ft_putstr("You won the game! Congratulations!\n");
		game_close(data);
	}
}

int	handle_key(int keycode, t_mlx_data *data)
{
	int	i;
	int	k;

	i = data->map.p_y;
	k = data->map.p_x;
	if (keycode == 65307)
		game_close(data);
	else if (keycode == A || keycode == LEFT)
		for_x(data, &i, &k, k - 1);
	else if (keycode == D || keycode == RIGHT)
		for_x(data, &i, &k, k + 1);
	else if (keycode == S || keycode == DOWN)
		for_y(data, &i, &k, i + 1);
	else if (keycode == W || keycode == UP)
		for_y(data, &i, &k, i - 1);
	map_parsing(data);
	rendering(data, TWIDTH, THEIGHT);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:28:52 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 00:36:17 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	args_nb(int ac)
{
	if (ac != 2)
	{
		ft_putstr("Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	format_check(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (!(s[i] == 'r' && s[i - 1] == 'e' && s[i - 2] == 'b' && s[i - 3] == '.'))
	{
		ft_putstr("Incorrect map format\n");
		exit(EXIT_FAILURE);
	}
}

void	input_handler(int ac, char **av)
{
	args_nb(ac);
	format_check(av[1]);
}

void	error_handler(int value)
{
	if (value < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}	

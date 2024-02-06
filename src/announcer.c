/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelosev <abelosev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:02:35 by abelosev          #+#    #+#             */
/*   Updated: 2024/02/05 00:26:00 by abelosev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	c = nb + '0';
	write(1, &c, 1);
}

void	moves_announcer(int nb)
{
	ft_putstr("You did ");
	ft_putnbr(nb);
	ft_putstr(" moves!\n");
}

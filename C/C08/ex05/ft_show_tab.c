/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:59:06 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 13:59:20 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ex05_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	ex05_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (0 <= nbr && nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		ex05_putnbr(-nbr);
	}
	else
	{
		ex05_putnbr(nbr / 10);
		ex05_putnbr(nbr % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ex05_putstr(par[i].str);
		ex05_putnbr(par[i].size);
		write(1, "\n", 1);
		ex05_putstr(par[i].copy);
		i++;
	}
}

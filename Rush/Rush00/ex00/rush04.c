/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:29:44 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/22 16:08:42 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check_first(int i, int x)
{
	if (i == 0)
		ft_putchar('A');
	else if (i == x - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
	return ;
}

void	check_last(int i, int x)
{
	if (i == 0)
		ft_putchar('C');
	else if (i == x - 1)
		ft_putchar('A');
	else
		ft_putchar('B');
	return ;
}

void	check(int i, int j, int x, int y)
{
	if (j == 0)
		check_first(i, x);
	else if (j == y - 1)
		check_last(i, x);
	else
	{
		if (i == 0 || i == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
	return ;
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((x <= 0) || (y <= 0))
		return ;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			check(i, j, x, y);
			i++;
		}
		j++;
		ft_putchar('\n');
	}
	return ;
}

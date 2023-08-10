/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:48:59 by gkim2             #+#    #+#             */
/*   Updated: 2023/07/22 14:09:04 by hyeonspa         ###   ########.fr       */
/*   Updated: 2023/07/22 13:13:21 by hyeonspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	check(int i, int j, int x, int y)
{
	if (j == 0)
	{
		if ((i == 0) || (i == x - 1))
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (j == y - 1)
	{
		if ((i == 0) || (i == x - 1))
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if ((i == 0) || (i == x - 1))
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

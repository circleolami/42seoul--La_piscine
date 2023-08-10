/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dankim <dankim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:08:07 by dankim            #+#    #+#             */
/*   Updated: 2023/07/22 14:17:32 by dankim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check(int i, int j, int x, int y)
{
	if (j == 0 || j == y - 1)
	{
		if (i == 0)
			ft_putchar ('A');
		else if (i == x -1)
			ft_putchar ('C');
		else
			ft_putchar ('B');
	}
	else
	{
		if ((i == 0) || (i == x - 1))
			ft_putchar ('B');
		else
			ft_putchar (' ');
	}
	return ;
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x > 0 && y > 0)
	{
		i = 0;
		j = 0;
		while (j < y)
		{
			i = 0;
			while (i < x)
			{
				check (i, j, x, y);
				i++;
			}
			j++;
			ft_putchar('\n');
		}
		return ;
	}
}

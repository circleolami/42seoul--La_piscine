/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:54:43 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/09 17:32:21 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex05_ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print(int i, int j, int k)
{
	ex05_ft_putchar(i);
	ex05_ft_putchar(j);
	ex05_ft_putchar(k);
	ex05_ft_putchar(',');
	ex05_ft_putchar(' ');
}

void	ft_print_last(int i, int j, int k)
{
	ex05_ft_putchar(i);
	ex05_ft_putchar(j);
	ex05_ft_putchar(k);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				if (! ((i == '7') && (j == '8')))
					ft_print(i, j, k);
				else
					ft_print_last(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
	return ;
}

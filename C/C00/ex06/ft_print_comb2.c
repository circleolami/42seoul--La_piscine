/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 08:07:57 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/09 17:32:51 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex06_ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ex06_ft_print(int d)
{
	char	a;
	char	b;

	a = (d / 10) + 48;
	b = (d % 10) + 48;
	ex06_ft_putchar(a);
	ex06_ft_putchar(b);
}

void	ft_result(int n, int m)
{
	ex06_ft_print(n);
	ex06_ft_putchar(' ');
	ex06_ft_print(m);
	if (!((n == 98) && (m == 99)))
	{
		ex06_ft_putchar(',');
		ex06_ft_putchar(' ');
	}
	return ;
}

void	ft_print_comb2(void)
{
	int	n;
	int	m;

	n = 0;
	while (n < 99)
	{
		m = n + 1;
		while (m < 100)
		{
			ft_result(n, m);
			m++;
		}
		n++;
	}
	return ;
}

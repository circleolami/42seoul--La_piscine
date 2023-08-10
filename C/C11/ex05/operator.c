/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:29:44 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:19:43 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
}

void	ft_minus(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
}

void	ft_multi(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	ft_putnbr(a / b);
	write(1, "\n", 1);
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_putnbr(a % b);
	write(1, "\n", 1);
}

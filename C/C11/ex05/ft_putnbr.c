/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:29:32 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:19:18 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operator.h"

void	put_char(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long	positive;
	int			is_negative;
	char		num[12];
	int			digits;

	digits = 0;
	is_negative = 0;
	if (nb < 0)
	{
		is_negative = 1;
		positive = -(long long)nb;
	}
	else
		positive = nb;
	if (is_negative)
		write(1, "-", 1);
	while (positive >= 10)
	{
		num[digits] = positive % 10 + '0';
		positive /= 10;
		digits++;
	}
	num[digits++] = positive % 10 + '0';
	while (--digits >= 0)
		put_char(num[digits]);
}

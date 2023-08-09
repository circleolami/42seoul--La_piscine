/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:36:52 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/09 17:33:05 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	int_to_str(long long n)
{
	char	arr[20];
	int		size;
	int		i;
	int		temp;

	size = 0;
	while (n > 0)
	{
		arr[size] = n % 10 + '0';
		n = n / 10;
		size++;
	}
	i = 0;
	while (i < size / 2)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
		i++;
	}
	write(1, arr, size);
}

void	ft_putnbr(int nb)
{
	long long	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = - (long long)nb;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else
		n = nb;
	int_to_str(n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:01:13 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/09 17:31:16 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ex08_ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ex08_ft_print(int nb, int *arr, int pos)
{
	int	i;

	if (pos == 1)
	{
		ex08_ft_putchar(',');
		ex08_ft_putchar(' ');
	}
	i = 0;
	while (i < nb)
	{
		ex08_ft_putchar(arr[i] + '0');
		i++;
	}
}

void	ft_change(int nb, int *arr)
{
	int	i;
	int	max;

	i = nb - 1;
	max = 9;
	while (arr[i] == max)
	{
		i--;
		max--;
	}
	arr[i]++;
	while (i < nb)
	{
		arr[i + 1] = arr[i] + 1;
		i++;
	}
}

void	ft_print_combn(int nb)
{
	int	i;
	int	arr[10];

	i = 0;
	while (i < nb)
	{
		arr[i] = i;
		i++;
	}
	ex08_ft_print(nb, arr, 0);
	while (arr[0] != 10 - nb || arr[nb - 1] != 9)
	{
		if (arr[nb - 1] != 9)
			arr[nb - 1] += 1;
		else
			ft_change(nb, arr);
		ex08_ft_print(nb, arr, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 03:11:57 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:53:15 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexadecimals(char c)
{
	char	str[2];
	int		idx;

	idx = 0;
	str[0] = (c >> 4) & 0b1111;
	str[1] = c & 0b1111;
	while (idx <= 1)
	{
		if (str[idx] >= 0 && str[idx] <= 9)
			str[idx] = str[idx] + '0';
		else
			str[idx] = str[idx] + 'a' - 10;
		idx++ ;
	}
	write(1, "\\", 1);
	write(1, str, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] != 127)
			write(1, &str[i], 1);
		else
			print_hexadecimals(str[i]);
		i++ ;
	}
}

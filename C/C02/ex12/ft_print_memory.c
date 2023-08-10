/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 03:17:11 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:53:45 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexadecimal_char(char c)
{
	char	hex[2];
	int		i;

	i = 1;
	while (i >= 0)
	{
		if ((c & 0b1111) <= 9)
			hex[i] = (c & 0b1111) + '0';
		else
			hex[i] = (c & 0b1111) - 10 + 'a';
		c = c >> 4;
		i-- ;
	}
	write(1, hex, 2);
}

void	print_memory(void *add)
{
	long long	ptr;
	char		address[16];
	int			size;

	size = 15;
	ptr = (long long)add;
	while (size >= 0)
	{
		if (ptr != 0)
		{
			if ((ptr & 0b1111) <= 9)
				address[size--] = (ptr & 0b1111) + '0';
			else
				address[size--] = ((ptr & 0b1111) - 10 + 'a');
			ptr = (ptr >> 4);
		}
		else
			address[size--] = '0';
	}
	write(1, address, 16);
	write(1, ": ", 2);
}

void	print_char(char *addr, int pos, int size)
{
	int		i;

	i = 0;
	while (i <= 15 && (pos + i) < size)
	{
		print_hexadecimal_char(addr[pos + i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		if ((pos + i) == size - 1 && i % 2 == 0)
		{
			write(1, "   ", 3);
			i++;
			break ;
		}
		i++;
	}
	while (i <= 14)
	{
		if (i == 16)
			write(1, " ", 1);
		else
			write(1, "     ", 5);
		i += 2;
	}
}

void	print_str(char *addr, int pos, int size)
{
	int	i;

	i = pos;
	while (i <= pos + 15)
	{
		if (addr[i] >= ' ' && addr[i] != 127)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		if (i == size - 1)
			break ;
		i++ ;
	}
}

void	*ft_print_memory(void *addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		print_memory(&addr[i]);
		print_char((char *)addr, i, size);
		print_str((char *)addr, i, size);
		i = i + 16;
		write(1, "\n", 1);
	}
	return (addr);
}

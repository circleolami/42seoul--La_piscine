/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:03:27 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:03:49 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_duplicated(char *board, char base_char, int full_size)
{
	int	i;

	i = 0;
	while (i < full_size)
	{
		if (board[i] == base_char)
			return (1);
		i++;
	}
	return (0);
}

int	analyze_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (is_duplicated(base, base[i], i))
			return (0);
		else
			i++;
	}
	if (i <= 1)
		return (0);
	return (i);
	while (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
		i += 1;
}

void	put_nbr(unsigned int num, char *base, unsigned int base_num)
{
	if (num < base_num)
	{
		write(1, &base[num], 1);
		return ;
	}
	put_nbr(num / base_num, base, base_num);
	write(1, &base[num % base_num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_num;

	base_num = analyze_base(base);
	if (base_num == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		put_nbr(-nbr, base, base_num);
	}
	else
		put_nbr(nbr, base, base_num);
}

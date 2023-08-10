/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:53:52 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 13:54:03 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	check_base(char *base)
{
	int	i;
	int	prev;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (9 <= base[i] && base[i] <= 13))
			return (0);
		prev = 0;
		while (prev < i)
		{
			if (base[prev] == base[i])
				return (0);
			prev++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	reverse(char *str, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - 1 - i];
		str[size - 1 - i] = temp;
		i++;
	}
}

void	fill_to_based(char *new, int nbr, char *base_to, int base_num)
{
	int			i;
	int			negative;
	long long	temp;

	negative = 0;
	if (nbr < 0)
	{
		negative = 1;
		temp = -(long long)nbr;
	}
	else
		temp = (long long)nbr;
	i = 0;
	while (temp != 0)
	{
		new[i++] = base_to[temp % base_num];
		temp /= (long long)base_num;
	}
	if (negative)
		new[i++] = '-';
	reverse(new, i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	int		i;
	int		check[2];
	char	*nbr_to_based;

	nbr_to_based = (char *)malloc(34 * sizeof(char));
	check[0] = check_base(base_from);
	check[1] = check_base(base_to);
	if (check[0] <= 1 || check[1] <= 1 || nbr_to_based == NULL)
		return (NULL);
	i = 0;
	while (i < 34)
		nbr_to_based[i++] = '\0';
	decimal = ft_atoi_base(nbr, base_from);
	if (decimal == 0)
		nbr_to_based[0] = base_to[0];
	else
		fill_to_based(nbr_to_based, decimal, base_to, check[1]);
	return (nbr_to_based);
}

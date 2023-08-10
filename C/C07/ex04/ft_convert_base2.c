/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:54:09 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 13:54:26 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	skip_white(char *str, int *cursor_out)
{
	int	i;

	i = *cursor_out;
	while (str[i])
	{
		if ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
			i++;
		else
			break ;
	}
	*cursor_out = i;
}

int	get_sign(char *str, int *cursor_out)
{
	int	i;
	int	negative;

	negative = 0;
	i = *cursor_out;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1 - negative;
		i++;
	}
	*cursor_out = i;
	return (negative);
}

int	get_base(char *base, int *base_to_num)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		else if (base[i] >= 9 && base[i] <= 13)
			return (0);
		else if (base_to_num[base[i] + 128] != -1)
			return (0);
		base_to_num[base[i] + 128] = i;
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

long long	calculate(char *str, int *base_to_num, int start, int base_num)
{
	int			offset;
	int			num[33];
	int			digit;
	long long	result;

	digit = 1;
	offset = 0;
	result = 0;
	while (str[start + offset])
	{
		if (base_to_num[str[start + offset] + 128] == -1)
			break ;
		num[offset] = base_to_num[str[start + offset] + 128];
		offset++;
	}
	while (--offset >= 0)
	{
		result += num[offset] * digit;
		digit *= base_num;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	result;
	int			base_num;
	int			negative;
	int			base_to_num[257];
	int			i;

	i = 0;
	while (i < 257)
		base_to_num[i++] = -1;
	i = 0;
	skip_white(str, &i);
	negative = get_sign(str, &i);
	base_num = get_base(base, base_to_num);
	result = calculate(str, base_to_num, i, base_num);
	if (negative)
		return (-result);
	return (result);
}

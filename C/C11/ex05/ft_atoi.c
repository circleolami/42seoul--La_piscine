/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:29:12 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:19:01 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	delete_space(char *str, int *cursor_out)
{
	int	cursor;
	int	i;

	i = 0;
	cursor = *cursor_out;
	while (str[cursor] != '\0')
	{
		if ((str[cursor] >= 9 && str[cursor] <= 13) || str[cursor] == ' ')
			cursor++;
		else
			break ;
	}
	*cursor_out = cursor;
}

int	extract_sign(char *str, int *cursor_out)
{
	int	cursor;
	int	negative;
	int	i;

	i = 0;
	cursor = *cursor_out;
	negative = 0;
	while (str[cursor] == '+' || str[cursor] == '-')
	{
		if (str[cursor] == '-')
			negative = 1 - negative;
		cursor++ ;
	}
	*cursor_out = cursor;
	return (negative);
}

int	calculate_digit(int *num, int size, int negative)
{
	int			digit;
	long long	sum;

	digit = 1;
	sum = 0;
	size -= 1;
	while (size >= 0)
	{
		sum += num[size] * digit;
		digit *= 10;
		size--;
	}
	if (negative)
		return (-sum);
	return (sum);
}

int	ft_atoi(char *str)
{
	int			cursor;
	int			start;
	int			num[20];
	int			negative;

	cursor = 0;
	delete_space(str, &cursor);
	negative = extract_sign(str, &cursor);
	start = cursor;
	while (str[cursor] != '\0')
	{
		if (str[cursor] >= '0' && str[cursor] <= '9')
		{
			num[cursor - start] = str[cursor] - '0';
			cursor++;
		}
		else
			break ;
	}
	return (calculate_digit(num, cursor - start, negative));
}

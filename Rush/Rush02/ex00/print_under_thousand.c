/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_under_thousand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejilee <jaejilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:04:23 by jaejilee          #+#    #+#             */
/*   Updated: 2023/08/06 17:58:15 by jaejilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_others.h"
#include <unistd.h>

void	print_100(char **dic);
void	print_n_ten(char **dic, int num);
void	print_n(char **dic, int num);
void	print_last(int last_3, int num);

void	print_under_thousand(char *small, char **dic, int last_3)
{
	int		num;
	char	temp[4];
	int		i;

	i = 0;
	ft_strlcpy(temp, small, 4);
	num = ft_atoi(temp);
	if (num >= 100)
	{
		print_n(dic, num / 100);
		write(1, " ", 1);
		print_100(dic);
		write(1, " ", 1);
	}
	num %= 100;
	if (num >= 20 && num <= 99)
	{
		print_n_ten(dic, num);
		write(1, " ", 1);
		print_n(dic, num % 10);
	}
	else if (num >= 1 && num <= 19)
		print_n(dic, num);
	print_last(last_3, num);
}

void	print_100(char **dic)
{
	write(1, dic[28], ft_strlen(dic[28]));
}

void	print_n_ten(char **dic, int num)
{
	if (num == 10)
		write(1, dic[10], ft_strlen(dic[10]));
	else
		write(1, dic[18 + (num / 10)], ft_strlen(dic[18 + (num / 10)]));
}

void	print_n(char **dic, int num)
{
	if (num == 0)
		return ;
	write(1, dic[num], ft_strlen(dic[num]));
}

void	print_last(int last_3, int num)
{
	if (last_3 != 3)
	{
		if (num != 0)
			write(1, " ", 1);
	}
	else
		write(1, "\n", 1);
}

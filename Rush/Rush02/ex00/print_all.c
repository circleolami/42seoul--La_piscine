/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejilee <jaejilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:54:44 by jaejilee          #+#    #+#             */
/*   Updated: 2023/08/06 18:42:28 by jaejilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_others.h"
#include <unistd.h>
#include <stdlib.h>

void	print_under_thousand(char *small, char **dic, int last_3);
void	print_unit(int order, char **dic);
int		is_zero(char *num);

void	print_all(int depth, int total, char *num, char **dic)
{
	if (ft_strcmp(num, "000") == 0)
	{
		write(1, dic[0], sizeof(dic[0]));
		write(1, "\n", 1);
		return ;
	}
	if (depth == total)
		return ;
	else if (total == 3 && depth == 0)
	{
		if (ft_strcmp(num + total, "000") == 0)
			write(1, dic[0], 1);
		else
			print_under_thousand(num + depth, dic, total - depth);
		print_all(depth + 3, total, num, dic);
	}
	else
	{
		print_under_thousand(num + depth, dic, total - depth);
		if (is_zero(num + depth) == 0 && total - depth != 3)
			print_unit((total - depth), dic);
		print_all(depth + 3, total, num, dic);
	}
}

void	print_unit(int order, char **dic)
{
	if (order == 12)
		write(1, dic[31], ft_strlen(dic[31]));
	else if (order == 9)
		write(1, dic[30], ft_strlen(dic[30]));
	else if (order == 6)
		write(1, dic[29], ft_strlen(dic[29]));
	write(1, " ", 1);
}

int	is_zero(char *num)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (num[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

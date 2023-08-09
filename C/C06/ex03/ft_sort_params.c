/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:19:46 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:20:12 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ex03_ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ex03_ft_print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		min;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		min = i;
		j = i;
		while (j < argc)
		{
			if (ex03_ft_strcmp(argv[j], argv[min]) < 0)
				min = j;
			j++;
		}
		temp = argv[i];
		argv[i] = argv[min];
		argv[min] = temp;
		i++;
	}
	i = 1;
	while (i < argc)
		ex03_ft_print(argv[i++]);
	return (0);
}

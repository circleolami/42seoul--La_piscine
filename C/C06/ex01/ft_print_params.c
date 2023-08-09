/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:17:50 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:21:03 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

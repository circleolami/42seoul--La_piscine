/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:18:43 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:19:36 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	i = argc - 1;
	while (i > 0)
	{
		str = argv[i];
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}

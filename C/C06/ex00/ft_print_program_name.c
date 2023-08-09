/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:13:53 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:20:51 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 1)
		return (0);
	str = argv[0];
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:28:26 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:18:34 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./operator.h"

void	parse_arguments(char *av[], int *arg)
{
	arg[0] = ft_atoi(av[1]);
	arg[1] = -1;
	if (av[2][0] == '+')
		arg[1] = 0;
	else if (av[2][0] == '-')
		arg[1] = 1;
	else if (av[2][0] == '*')
		arg[1] = 2;
	else if (av[2][0] == '/')
		arg[1] = 3;
	else if (av[2][0] == '%')
		arg[1] = 4;
	arg[2] = ft_atoi(av[3]);
}

int	main(int ar, char *av[])
{
	int		arguments[3];
	void	(*f[5])(int, int);

	if (ar != 4)
		return (0);
	parse_arguments(av, arguments);
	f[0] = ft_add;
	f[1] = ft_minus;
	f[2] = ft_multi;
	f[3] = ft_div;
	f[4] = ft_mod;
	if (arguments[1] == -1)
	{
		ft_putnbr(0);
		write(1, "\n", 1);
		return (0);
	}
	f[arguments[1]](arguments[0], arguments[2]);
	return (0);
}

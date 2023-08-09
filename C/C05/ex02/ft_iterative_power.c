/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:08:28 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:08:35 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	sum;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	sum = 1;
	while (power)
	{
		sum *= nb;
		power --;
	}
	return (sum);
}

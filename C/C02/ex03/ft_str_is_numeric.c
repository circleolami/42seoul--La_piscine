/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:46:15 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:48:11 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	check;

	check = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			str++;
			continue ;
		}
		else
		{
			check = 1;
			str++;
			break ;
		}
	}
	if (check)
		return (0);
	else
		return (1);
}

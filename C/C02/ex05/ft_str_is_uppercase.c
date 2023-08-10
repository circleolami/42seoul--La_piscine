/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:18:15 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:51:28 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	check;

	check = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			str++;
			continue ;
		}
		else
		{
			check = 1;
			str++;
		}
	}
	if (check)
		return (0);
	else
		return (1);
}

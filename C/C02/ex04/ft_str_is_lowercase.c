/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2R@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:53:12 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:48:32 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	check;

	check = 0;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
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

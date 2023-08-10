/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 01:53:22 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:51:57 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	check;

	check = 0;
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
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

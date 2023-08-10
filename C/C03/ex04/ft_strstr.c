/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:54:30 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:10:55 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	if (!ft_strlen(to_find))
		return (str);
	while (str[i])
	{
		j = 0;
		check = 1;
		while (to_find[j])
		{
			if (to_find[j] != str[i + j])
			{
				check = 0;
				break ;
			}
			j++;
		}
		if (check)
			return (&str[i]);
		str++;
	}
	return (0);
}

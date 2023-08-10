/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:58:46 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 13:59:02 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *src)
{
	int	size;

	size = 0;
	while (src[size] != '\0')
		size++;
	return (size);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;
	int			temp;

	i = 0;
	arr = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (arr == NULL)
		return (NULL);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		temp = sizeof(char) * (ft_strlen(arr[i].str) + 1);
		arr[i].copy = (char *)malloc(temp);
		if (arr[i].copy == NULL)
			return (NULL);
		ft_strcpy(arr[i].copy, av[i]);
		i++;
	}
	arr[ac].str = NULL;
	return (arr);
}

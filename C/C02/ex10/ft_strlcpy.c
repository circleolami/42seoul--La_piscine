/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:51:10 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:52:59 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	length;
	unsigned int	idx;

	idx = 0;
	length = 0;
	while (src[length] != '\0')
	{
		length++ ;
	}
	if (size <= 0)
		return (length);
	while (idx < size - 1 && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++ ;
	}
	dest[idx] = '\0';
	return (length);
}

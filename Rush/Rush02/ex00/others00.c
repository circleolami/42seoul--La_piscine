/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmol <seungmol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:44:12 by seungmol          #+#    #+#             */
/*   Updated: 2023/08/06 16:03:17 by jaejilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "others00.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

int	ft_atoi(char *str)
{
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	while (*(str) && (*(str) < '0' || *(str) > '9'))
	{
		if (*(str) != '+' && *(str) != '-' && *(str) != ' ' && *(str) != '\t' \
		&& *(str) != '\n' && *(str) != '\v' && *(str) != '\f' && *(str) != '\r')
			return (0);
		if (*(str) == '-')
			sign *= -1;
		str++;
	}
	while (*(str) && '0' <= *(str) && *(str) <= '9')
	{
		n *= 10;
		if (sign < 0)
			n -= *(str) - '0';
		else
			n += *(str) - '0';
		str++;
	}
	return (n);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_size;

	i = 0;
	src_size = 0;
	while (src[src_size] != '\0')
	{
		src_size++;
	}
	if (size == 0)
		return (src_size);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	len;
	unsigned int	i;

	d_len = (unsigned int)ft_strlen(dest);
	s_len = (unsigned int)ft_strlen(src);
	if (d_len < size)
		len = s_len + d_len;
	else
		len = s_len + size;
	if (size < 1)
		return (len);
	i = 0;
	while (*(src + i) != '\0' && i + d_len < size - 1)
	{
		*(dest + d_len + i) = *(src + i);
		i++;
	}
	*(dest + d_len + i) = '\0';
	return (len);
}

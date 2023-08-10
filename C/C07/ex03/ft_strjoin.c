/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:53:26 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 13:53:36 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	total_len(char **strs, int size)
{
	int	index_of_word;
	int	cnt;

	cnt = 0;
	index_of_word = 0;
	while (index_of_word < size)
	{
		cnt += ft_strlen(strs[index_of_word]);
		index_of_word++;
	}
	return (cnt);
}

void	concat_sep(char *str, char *sep, int *cursor_out)
{
	int	i;

	i = *cursor_out;
	while (*sep != '\0')
	{
		str[i] = *sep;
		i++;
		sep++;
	}
	str[i] = '\0';
	*cursor_out = i;
}

char	*free_str(void)
{
	char	*empty;

	empty = (char *)malloc(sizeof(char));
	if (empty == NULL)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		j;
	int		offset;
	int		temp;

	if (size <= 0)
		return (free_str());
	temp = total_len(strs, size) + ft_strlen(sep) * (size - 1) + 1;
	join = (char *)malloc(temp * sizeof(char));
	i = 0;
	j = 0;
	while (i < size)
	{
		offset = -1;
		while (strs[i][++offset] != '\0')
			join[j++] = strs[i][offset];
		if (i < size - 1)
			concat_sep(join, sep, &j);
		i++;
	}
	join[j] = '\0';
	return (join);
}

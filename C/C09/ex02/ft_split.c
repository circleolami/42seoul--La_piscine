/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:28:58 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 14:29:11 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_word_count(char *str, char *charset)
{
	int	cnt;
	int	index;
	int	is_word;

	cnt = 0;
	index = 0;
	is_word = 0;
	while (str[index])
	{
		if (!is_seperator(str[index], charset) && !is_word)
			is_word = 1;
		else if (is_seperator(str[index], charset) && is_word)
		{
			cnt++;
			is_word = 0;
		}
		index++;
	}
	cnt += is_word;
	return (cnt);
}

char	*get_word(char *str, char *charset, int *start)
{
	int		i;
	char	*word;
	int		idx_word;

	i = *start;
	while (str[i])
	{
		if (is_seperator(str[i], charset))
			break ;
		i++;
	}
	word = (char *)malloc((i - *start + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	idx_word = 0;
	while (idx_word < (i - *start))
	{
		word[idx_word] = str[*start + idx_word];
		idx_word++;
	}
	word[idx_word] = '\0';
	*start = i;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		word_cnt;
	char	**result;
	int		idx_result;
	int		idx_str;

	word_cnt = get_word_count(str, charset);
	result = (char **)malloc((word_cnt + 1) * sizeof(char *));
	idx_result = 0;
	idx_str = 0;
	if (result == NULL)
		return (NULL);
	while (str[idx_str])
	{
		if (!is_seperator(str[idx_str], charset))
		{
			result[idx_result] = get_word(str, charset, &idx_str);
			if (result[idx_result++] == NULL)
				break ;
		}
		if (str[idx_str])
			idx_str++;
	}
	result[idx_result] = NULL;
	return (result);
}

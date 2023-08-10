/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:26:48 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 14:26:58 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	cursor;

	cursor = 0;
	while (s1[cursor] == s2[cursor] && s1[cursor])
		cursor++;
	return (s1[cursor] - s2[cursor]);
}

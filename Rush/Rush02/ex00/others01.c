/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmol <seungmol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:19:35 by seungmol          #+#    #+#             */
/*   Updated: 2023/08/06 14:27:06 by seungmol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int	i;
	int	cmp;

	i = 0;
	while (*(str1 + i) != '\0' || *(str2 + i) != '\0')
	{
		cmp = (unsigned char)*(str1 + i) - (unsigned char)*(str2 + i);
		if (cmp != 0)
			return (cmp);
		i++;
	}
	return (0);
}

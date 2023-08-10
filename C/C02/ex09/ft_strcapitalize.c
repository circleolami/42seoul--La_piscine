/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 02:47:08 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 18:52:44 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_plain_char(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	while (str[i] != '\0')
	{
		if (is_plain_char(str[i]) == 0)
			first = 1;
		else
		{
			if (first == 1 && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
			else if (first == 0 && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
			first = 0;
		}
		i++ ;
	}
	return (str);
}

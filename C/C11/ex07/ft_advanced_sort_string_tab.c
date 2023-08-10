/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 02:05:56 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/11 02:17:33 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	tab_len(char **tab)
{
	int	cnt;

	cnt = 0;
	while (tab[cnt] != 0)
		cnt++;
	return (cnt);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		len;
	int		i;
	int		j;

	len = tab_len(tab);
	if (len <= 1)
		return ;
	i = len - 1;
	while (i >= 1)
	{
		j = 1;
		while (j <= i)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i--;
	}
}

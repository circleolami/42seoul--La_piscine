/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejilee <jaejilee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:33:42 by jaejilee          #+#    #+#             */
/*   Updated: 2023/08/06 17:45:42 by jaejilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all_others.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		parse(char *addr, char **dir);
void	print_all(int depth, int total, char *num, char **dic);
char	*is_valid(char *str);
void	dic_free(char **dic);
char	*make_pretty(char *str);
int		valid_argc(int argc, char *argv[], char *pretty_number, char **dic);
int		valid_print(char *pretty_number, char **dic);

int	main(int argc, char *argv[])
{
	char	*dic[32];
	char	*pretty_number;
	int		i;

	if (!(argc == 2 || argc == 3))
	{
		write(2, "error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 32)
	{
		dic[i] = 0;
		i++;
	}
	pretty_number = is_valid(argv[argc - 1]);
	if (valid_argc(argc, argv, pretty_number, dic) == 0)
		return (0);
	valid_print(pretty_number, dic);
	return (0);
}

char	*is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (ft_strdup("0"));
	while (str[i + j] != '\0')
	{
		if (!(str[i + j] >= '0' && str[i + j] <= '9'))
			return (0);
		j++;
	}
	return (ft_strdup(str + i));
}

char	*make_pretty(char *str)
{
	char	*res;
	int		len;
	int		add;
	int		i;

	len = ft_strlen(str);
	add = len % 3;
	res = malloc(sizeof(char) * (len + add));
	i = 0;
	while (add != 0 && i < (3 - add))
	{
		res[i] = '0';
		i++;
	}
	ft_strlcat(res + i, str, len + 1);
	free(str);
	return (res);
}

int	valid_argc(int argc, char *argv[], char *pretty_number, char **dic)
{
	if (pretty_number == 0)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		if (parse("numbers.dict", dic) == -1)
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
	}
	else if (argc == 3)
	{
		if (parse(argv[1], dic) == -1)
		{
			write(2, "Dict Error\n", 11);
			return (0);
		}
	}
	return (1);
}

int	valid_print(char *pretty_number, char **dic)
{
	pretty_number = make_pretty(pretty_number);
	if (ft_strlen(pretty_number) > 12)
	{
		write(2, "error\n", 6);
		return (0);
	}
	else
		print_all(0, ft_strlen(pretty_number), pretty_number, dic);
	free(pretty_number);
	dic_free(dic);
	return (0);
}

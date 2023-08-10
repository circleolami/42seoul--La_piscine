/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:59:39 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/06 18:32:26 by jaejilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "all_others.h"

int		check_file_size(int bf, char **dic);
int		read_file(char *buf, char **dic, int size);
int		parse(char *addr, char **dic);
void	put_dic(char **dic, char *str_value, int *arr, int str_key);
void	dic_free(char **dic);

int	check_file_size(int bf, char **dic)
{
	char		*buf;
	ssize_t		size;

	buf = (char *)malloc(sizeof(char) * 4000000);
	size = read(bf, buf, 4000000);
	if (size == -1)
	{
		free(buf);
		write(1, "Dict Size Error\n", 16);
		return (-1);
	}
	else
	{
		if (read_file(buf, dic, size) == -1)
		{
			free(buf);
			return (-1);
		}
	}
	free(buf);
	return (0);
}

int	read_file(char *buf, char **dic, int size)
{
	int		i;
	int		j;
	int		temp;
	int		str_key;
	char	temp_key[4000000];
	char	str_value[4000000];
	int		arr[32];
	int		flag;

	i = -1;
	while (++i < 21)
		arr[i] = i;
	temp = 30;
	while (i < 29)
	{
		arr[i] = temp;
		temp += 10;
		i++;
	}
	arr[29] = 1000;
	arr[30] = 1000000;
	arr[31] = 1000000000;
	i = 0;
	flag = 0;
	while (i < size)
	{
		j = 0;
		while ('0' <= buf[i] && buf[i] <= '9')
		{
			temp_key[j] = buf[i];
			i++;
			j++;
		}
		if (buf[i] != ':' && buf[i] != '\n')
		{
			flag = 1;
			break ;
		}
		i += 1;
		str_key = ft_atoi(temp_key);
		j = 0;
		while (buf[i] == ' ')
			i++;
		while (buf[i] != '\n')
		{
			str_value[j] = buf[i];
			i++;
			j++;
		}
		str_value[j] = '\0';
		put_dic(dic, str_value, arr, str_key);
		i++;
	}
	if (flag)
	{
		dic_free(dic);
		return (-1);
	}
	return (0);
}

void	put_dic(char **dic, char *str_value, int *arr, int str_key)
{
	int	i;
	int	pos;
	int	size_value;

	i = 0;
	while (i < 32)
	{
		if (str_key == arr[i])
		{
			size_value = ft_strlen(str_value);
			pos = i;
			dic[pos] = (char *)malloc(sizeof(char) * (size_value + 1));
			ft_strlcpy(dic[pos], str_value, size_value + 1);
			return ;
		}
		i++;
	}
	return ;
}

int	parse(char *addr, char **dic)
{
	int		bf;

	bf = open(addr, O_RDONLY);
	if (bf == -1)
		return (-1);
	if (check_file_size(bf, dic) != 0)
		return (-1);
	close(bf);
	return (0);
}

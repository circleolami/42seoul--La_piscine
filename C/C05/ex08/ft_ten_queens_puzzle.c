/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim2 <gkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:11:35 by gkim2             #+#    #+#             */
/*   Updated: 2023/08/10 04:11:44 by gkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(int board[10], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (row == board[i])
			return (0);
		if (i + board[i] == col + row)
			return (0);
		if (i - board[i] == col - row)
			return (0);
		i++;
	}
	return (1);
}

void	ft_norm(int board[10], int *cnt, int i)
{
	*cnt = *cnt + 1;
	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

void	ft_count(int board[10], int *cnt, int pos)
{
	int	col;

	if (pos == 10)
		ft_norm(board, cnt, 0);
	else
	{
		col = 0;
		while (col < 10)
		{
			if (ft_check(board, pos, col))
			{
				board[pos] = col;
				ft_count(board, cnt, pos + 1);
			}
			col++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	ft_count(board, &cnt, 0);
	return (cnt);
}

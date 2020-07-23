/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:15:50 by juan              #+#    #+#             */
/*   Updated: 2020/07/14 10:02:57 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "check.h"
#include "utils2.h"
#include "print.h"
#include "free_memory.h"

int	g_size;
int	g_all_set;
int	**g_board;
int	*g_clue;

int	check_line(int idx, int offset, int *row, int *rev)
{
	if (!sub_increase_match(g_clue[g_size * offset + idx], row))
		return (0);
	if (!sub_increase_match(g_clue[g_size * (offset + 1) + idx], rev))
		return (0);
	return (1);
}

int	is_valid(int v, int i, int j)
{
	int *col_to_row;
	int *rev;

	if (!row_col_check(i, j, v))
		return (0);
	col_to_row = tranpose(j);
	g_board[i][j] = v;
	if (i == (g_size - 1))
	{
		col_to_row = tranpose(j);
		rev = reverse(col_to_row);
		if (check_line(j, 0, col_to_row, rev) == 0)
			return (0);
	}
	if (j == (g_size - 1))
	{
		rev = reverse(g_board[i]);
		if (check_line(i, 2, g_board[i], rev) == 0)
			return (0);
	}
	free(col_to_row);
	free(rev);
	return (1);
}

int	**init_board(void)
{
	int **g_board;
	int i;
	int j;

	g_board = (int**)malloc(g_size * sizeof(int*));
	i = 0;
	while (i < g_size)
	{
		g_board[i] = (int*)malloc(g_size * sizeof(int));
		j = 0;
		while (j < g_size)
			g_board[i][j++] = 0;
		i++;
	}
	return (g_board);
}

int	rush(int i, int j, int v)
{
	while (i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			if (g_board[i][j] == 0)
			{
				while (v <= g_size)
				{
					if (is_valid(v++, i, j) == 1)
					{
						rush(0, 0, 1);
						if (g_all_set)
							return (0);
						g_board[i][j] = 0;
					}
					else
						g_board[i][j] = 0;
				}
				return (0);
			}
		}
		i++;
	}
	return (g_all_set = 1);
}

int	main(int argc, char **argv)
{
	g_all_set = 0;
	if (argc != 2) // 인풋값이 1개 이상일 경우 에러
	{
		print_error();
		return (0);
	}
	g_size = ft_div_four(get_number_count(argv[1])); // 인풋 값이 네 방향에서 본 값이므로 나누기 4 값으로 올바른 인풋인지 판단
	if (g_size == 0) // 4 x 4 혹은 더 작거나 큰 값인가? 0은 invalid. 음수 값은 board를 0000000000으로 초기화.
	{
		print_error();
		return (0);
	}
	g_board = init_board(); // board 빈값으로 초기화
	g_clue = fill_clue(argv[1]); // clue를 문자에서 숫자 배열로!
	rush(0, 0, 1);
	if (g_board[0][0] == 0)
	{
		print_error();
		return (0);
	}
	print_board();
	free_memory();
}

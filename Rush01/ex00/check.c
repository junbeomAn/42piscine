/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjung <gjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:10:20 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 16:42:18 by gjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern	int	g_size;
extern	int	**g_board;

int	*reverse(int *row)
{
	int *rev;
	int i;

	rev = (int*)malloc(g_size * sizeof(int));
	i = 0;
	while (i < g_size)
	{
		rev[i] = row[g_size - 1 - i];
		i++;
	}
	return (rev);
}

int	*tranpose(int j)
{
	int *row;
	int i;

	row = (int*)malloc(g_size * sizeof(int));
	i = 0;
	while (i < g_size)
	{
		row[i] = g_board[i][j];
		i++;
	}
	return (row);
}

int	sub_increase_match(int clue, int *line)
{
	int increase;
	int max;
	int i;

	increase = 0;
	max = 0;
	i = 0;
	while (i < g_size)
	{
		if (max < line[i])
		{
			max = line[i];
			increase++;
		}
		i++;
	}
	return (increase == clue);
}

int	row_col_check(int i, int j, int value)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < g_size)
	{
		if (g_board[i][x] == value)
			return (0);
		x++;
	}
	while (y < g_size)
	{
		if (g_board[y][j] == value)
			return (0);
		y++;
	}
	return (1);
}

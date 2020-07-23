/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:44:11 by juan              #+#    #+#             */
/*   Updated: 2020/07/08 13:48:49 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_edge_row(int row, int col, int x, int y);
void	print_middle_row(int col, int x);

void	rush(int x, int y)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			if (row == 0 || row == y - 1)
			{
				print_edge_row(row, col, x, y);
			}
			else
			{
				print_middle_row(col, x);
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	print_edge_row(int row, int col, int x, int y)
{
	if ((row == 0 || row == y - 1) && (col == 0 || col == x - 1))
	{
		if ((row + col == 0 || (row && col && row + col == (x - 1) + (y - 1))))
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar('C');
		}
	}
	else
	{
		ft_putchar('B');
	}
}

void	print_middle_row(int col, int x)
{
	if (col == 0 || col == x - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

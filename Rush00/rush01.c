/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 09:05:44 by juan              #+#    #+#             */
/*   Updated: 2020/07/04 10:35:54 by juan             ###   ########.fr       */
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
	if ((row == 0 && col == 0) || (row == y - 1 && col == x - 1 && row && col))
	{
		ft_putchar('/');
	}
	else if ((row == y - 1 && col == 0) || (row == 0 && col == x - 1))
	{
		ft_putchar('\\');
	}
	else
	{
		ft_putchar('*');
	}
}

void	print_middle_row(int col, int x)
{
	if (col == 0 || col == x - 1)
	{
		ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

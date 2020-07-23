/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojlee <hojlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:24:18 by juan              #+#    #+#             */
/*   Updated: 2020/07/04 12:59:58 by hojlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_edge_row(int col, int x);
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
				print_edge_row(col, x);
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

void	print_edge_row(int col, int x)
{
	if (col == 0)
	{
		ft_putchar('A');
	}
	else if (col == x - 1)
	{
		ft_putchar('C');
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

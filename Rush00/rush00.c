/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojlee <hojlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 10:23:40 by hojlee            #+#    #+#             */
/*   Updated: 2020/07/04 12:48:38 by hojlee           ###   ########.fr       */
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
	if (col == 0 || col == x - 1)
	{
		ft_putchar('o');
	}
	else
	{
		ft_putchar('-');
	}
}

void	print_middle_row(int col, int x)
{
	if (col == 0 || col == x - 1)
	{
		ft_putchar('|');
	}
	else
	{
		ft_putchar(' ');
	}
}

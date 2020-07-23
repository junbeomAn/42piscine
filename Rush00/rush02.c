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

void	print_edge_row(int row, int col, int x);
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
				print_edge_row(row, col, x);
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

void	print_edge_row(int row, int col, int x)
{
	if (col == 0 || col == x - 1)
	{
		if (row == 0)
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

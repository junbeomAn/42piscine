/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:19:30 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 15:35:15 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	int	**g_board;
extern	int	g_size;

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_ch(char c)
{
	write(1, &c, 1);
}

void	print_board(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size)
		{
			c = (g_board[i][j] + '0');
			print_ch(c);
			if (j != g_size - 1)
				print_ch(' ');
			j++;
		}
		print_ch('\n');
		i++;
	}
}

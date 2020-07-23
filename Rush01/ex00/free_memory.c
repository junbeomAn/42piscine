/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:18:09 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 15:35:18 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern	int	**g_board;
extern	int	*g_clue;
extern	int	g_size;

void	free_memory(void)
{
	int i;

	i = 0;
	while (i < g_size)
		free(g_board[i++]);
	free(g_clue);
	free(g_board);
}

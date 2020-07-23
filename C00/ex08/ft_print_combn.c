/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:38:08 by juan              #+#    #+#             */
/*   Updated: 2020/07/04 21:28:38 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb(int start, int r, char *acc, int num)
{
	int i;

	if (r == 0)
	{
		write(1, acc, num);
		if ((acc[num - 1] == '9') && (acc[0] == '9' - num + 1))
			return ;
		write(1, ", ", 2);
		return ;
	}
	i = start;
	while (i < 10)
	{
		acc[num - r] = i + 48;
		comb(i + 1, r - 1, acc, num);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	char_num[15];
	int		count;

	count = n;
	comb(0, n, char_num, count);
}

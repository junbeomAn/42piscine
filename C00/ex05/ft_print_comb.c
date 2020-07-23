/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:54:01 by juan              #+#    #+#             */
/*   Updated: 2020/07/04 16:43:37 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb(int n, int start, char *acc)
{
	int i;

	if (n == 0)
	{
		write(1, acc, 3);
		if ((acc[0] == '7') && (acc[2] == '9'))
			return ;
		write(1, ", ", 2);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		acc[3 - n] = i + 48;
		comb(n - 1, i + 1, acc);
		i++;
	}
}

void	ft_print_comb(void)
{
	int		n;
	int		start;
	char	str[4];

	n = 3;
	start = 0;
	str[3] = '\0';
	comb(n, start, str);
}

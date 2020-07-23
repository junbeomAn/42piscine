/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 09:31:38 by juan              #+#    #+#             */
/*   Updated: 2020/07/19 18:32:54 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	put_nbr(int size)
{
	char c;

	if (size == 0)
		return ;
	put_nbr(size / 10);
	c = (size % 10) + '0';
	write(1, &c, 1);
}

void	put_chars(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		put_chars(par[i].str);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			put_nbr(par[i].size);
		write(1, "\n", 1);
		put_chars(par[i].copy);
		i++;
	}
}

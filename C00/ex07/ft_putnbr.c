/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:47:15 by juan              #+#    #+#             */
/*   Updated: 2020/07/05 09:14:52 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		convert(int n, int nb)
{
	if (nb / n > 0)
	{
		return (nb / n + 48);
	}
	else
	{
		return ((-(nb / n)) + 48);
	}
}

void	insert_number(int n, int nb)
{
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
	}
	while (n > 0)
	{
		c = convert(n, nb);
		write(1, &c, 1);
		nb = nb % n;
		n = n / 10;
	}
}

void	get_div_num(int nb, int *n)
{
	while (nb / 10)
	{
		nb /= 10;
		*n *= 10;
	}
}

void	ft_putnbr(int nb)
{
	int		n;

	n = 1;
	get_div_num(nb, &n);
	insert_number(n, nb);
}

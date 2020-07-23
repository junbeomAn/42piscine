/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:34:48 by juan              #+#    #+#             */
/*   Updated: 2020/07/04 21:32:23 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	handle_front(char *str, char *comma, int m, int n)
{
	while (n <= 99)
	{
		str[3] = (n / 10) + 48;
		str[4] = (n % 10) + 48;
		write(1, str, 5);
		if (m < 98)
		{
			write(1, comma, 2);
		}
		n++;
	}
}

void	handle_rear(char *str, char *comma, int m, int n)
{
	while (m <= 98)
	{
		str[0] = (m / 10) + 48;
		str[1] = (m % 10) + 48;
		n = m + 1;
		handle_front(str, comma, m, n);
		m++;
	}
}

void	ft_print_comb2(void)
{
	int		m;
	int		n;
	char	str[7];
	char	comma[3];

	m = 0;
	n = 0;
	str[2] = ' ';
	str[6] = '\0';
	comma[0] = ',';
	comma[1] = ' ';
	handle_rear(str, comma, m, n);
}

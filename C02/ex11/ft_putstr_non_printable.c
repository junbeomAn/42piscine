/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:35:11 by juan              #+#    #+#             */
/*   Updated: 2020/07/09 11:05:58 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	get_hex(unsigned char asc)
{
	char	c;

	c = asc + 48;
	if ('9' < c)
	{
		c = (int)c + 39;
	}
	return (c);
}

void	ascii_to_hex_str(unsigned char c)
{
	char	hex_str1;
	char	hex_str2;

	hex_str1 = get_hex(c / 16);
	hex_str2 = get_hex(c % 16);
	write(1, "\\", 1);
	write(1, &hex_str1, 1);
	write(1, &hex_str2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((' ' <= str[i] && str[i] <= '~'))
		{
			write(1, &str[i], 1);
		}
		else
		{
			ascii_to_hex_str(str[i]);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:27:08 by juan              #+#    #+#             */
/*   Updated: 2020/07/14 10:45:31 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	zero_init(char *arr)
{
	int i;

	i = 0;
	while (i < 127)
	{
		arr[i] = 0;
		i++;
	}
}

int		is_valid_base(char *base)
{
	char	ascii[127];
	int		i;

	i = 0;
	zero_init(ascii);
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ascii[(int)base[i]])
		{
			return (0);
		}
		ascii[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

void	base_convert(int nbr, char *base, int len)
{
	int div;
	int mod;

	if (!nbr)
		return ;
	div = nbr / len;
	mod = nbr % len;
	base_convert(div, base, len);
	if (mod < 0)
		mod = -mod;
	write(1, &base[mod], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = is_valid_base(base);
	if (!len)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
		write(1, "-", 1);
	base_convert(nbr, base, len);
}

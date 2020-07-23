/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:31:13 by juan              #+#    #+#             */
/*   Updated: 2020/07/15 13:57:49 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_valid_base(char *base)
{
	char	ascii[127];
	int		i;

	i = 0;
	while (i < 127)
		ascii[i++] = 0;
	i = 0;
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

int		base_convert(char *str, char *base, int len)
{
	int res;
	int value;
	int i;
	int sign;

	res = 0;
	sign = 0;
	while (*str)
	{
		i = 0;
		while (i < len && (*str != base[i]))
			i++;
		if (i < len)
		{
			value = i;
			res *= len;
			res += value;
		}
		else 
			break;
		str++;
	}
	return (res);
}

int		ft_putnbr_base(char *str, char *base)
{
	int len;
	int res;

	if (str[0] == '\0')
		return (0);
	len = is_valid_base(base);
	if (!len)
		return (0);
	res = base_convert(str, base, len);
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int		res;
	int		minus;

	minus = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
	|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	res = ft_putnbr_base(str, base);
	if (minus == -1)
		res *= -1;
	return (res);
}

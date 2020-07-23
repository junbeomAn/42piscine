/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 11:25:35 by juan              #+#    #+#             */
/*   Updated: 2020/07/14 21:16:17 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
	|| c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int minus;
	int num;

	minus = 1;
	num = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *str - 48;
		str++;
	}
	return (minus * num);
}

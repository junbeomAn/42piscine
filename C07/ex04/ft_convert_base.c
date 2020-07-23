/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:18:16 by juan              #+#    #+#             */
/*   Updated: 2020/07/18 20:12:36 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_is_white_space(char c);
int			ft_strlen(char *str);
int			get_num_len(long long num, long long b_len);

long long	base_from_convert(char *str, char *base, int len)
{
	long long	res;
	int			value;
	int			i;

	res = 0;
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
			break ;
		str++;
	}
	return (res);
}

char		*base_to_convert(long long num, int minus, char *base, int b_len)
{
	char	*res;
	int		n_len;
	int		i;

	n_len = get_num_len(num, b_len);
	i = 0;
	if (minus < 0)
		n_len++;
	res = (char *)malloc(sizeof(char) * (n_len + 1));
	res[n_len] = '\0';
	if (minus < 0)
		res[0] = '-';
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[--n_len] = base[num % b_len];
		num /= b_len;
	}
	return (res);
}

char		*ft_atoi_char(char *str, int *minus)
{
	*minus = 1;
	if (str == 0)
		return (str);
	while (ft_is_white_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus *= -1;
		str++;
	}
	return (str);
}

int			is_valid_base(char *base)
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
		if (base[i] == '+' || base[i] == '-' ||
			ascii[(int)base[i]] || ft_is_white_space(base[i]))
			return (0);
		ascii[(int)base[i]] = 1;
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			base_length;
	int			minus;
	long long	temp;
	char		*str;
	char		*ret;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (0);
	str = ft_atoi_char(nbr, &minus);
	base_length = ft_strlen(base_from);
	temp = base_from_convert(str, base_from, base_length);
	base_length = ft_strlen(base_to);
	ret = base_to_convert(temp, minus, base_to, base_length);
	return (ret);
}

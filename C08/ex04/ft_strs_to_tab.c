/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:16:44 by juan              #+#    #+#             */
/*   Updated: 2020/07/19 18:23:10 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void				ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

int					ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}

int					put_struct_to_arr(t_stock_str *arr, char *s, int i)
{
	int			str_len;
	char		*dest;

	str_len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!dest)
		return (0);
	dest[str_len] = '\0';
	ft_strcpy(dest, s);
	arr[i].size = str_len;
	arr[i].str = s;
	arr[i].copy = dest;
	return (1);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s_arr;
	int			i;
	int			is_error;

	s_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	if (!s_arr)
		return (0);
	while (i < ac)
	{
		is_error = put_struct_to_arr(s_arr, av[i], i);
		if (is_error == 0)
			return (0);
		i++;
	}
	s_arr[i].str = 0;
	return (s_arr);
}

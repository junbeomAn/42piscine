/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjung <gjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:20:36 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 16:40:16 by gjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_div_four(int nb)
{
	int mod;

	mod = nb % 4;
	if (mod == 0 && (nb / 4) >= 1)
		return (nb / 4);
	return (0);
}

int		is_space(char c)
{
	return (c == ' ');
}

int		is_numeric(char c)
{
	if ('0' < c && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	*get_number(char *str, int *length)
{
	int start_index;
	int end_index;

	start_index = 0;
	while (is_numeric(str[start_index]) != 1)
	{
		if (str[start_index] == '\0')
			return (0);
		if (is_space(str[start_index]) == 0)
			return (0);
		start_index++;
	}
	end_index = 0;
	while (is_space(str[start_index + end_index]) != 1)
	{
		if (str[start_index + end_index] == '\0')
			break ;
		if (is_numeric(str[start_index + end_index]) == 0)
			return (0);
		end_index++;
	}
	*length = end_index;
	return (&str[start_index]);
}

int		get_number_count(char *str)
{
	int		number_count;
	char	*ptr;
	int		length;

	ptr = str;
	number_count = 0;
	length = 0;
	while (1)
	{
		ptr = get_number(ptr, &length);
		if (ptr == 0)
			break ;
		ptr = &ptr[length + 1];
		number_count++;
	}
	return (number_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:21:41 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 15:21:42 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "print.h"

char	*ft_cpstr(char *str, int length)
{
	char	*result;
	int		index;

	result = (char*)malloc((length + 1) * sizeof(char));
	index = 0;
	while (index < length)
	{
		result[index] = str[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

char	**get_number_word(char *str)
{
	int		index;
	int		number_count;
	char	*ptr;
	int		length;
	char	**result;

	number_count = get_number_count(str);
	result = (char **)malloc(number_count * sizeof(char *));
	ptr = str;
	length = 0;
	index = 0;
	while (1)
	{
		ptr = get_number(ptr, &length);
		if (ptr == 0)
			break ;
		result[index] = ft_cpstr(ptr, length);
		ptr = &ptr[length + 1];
		index++;
	}
	return (result);
}

int		str_to_int(char *str)
{
	int index;
	int length;
	int result;
	int base;

	length = 0;
	base = 1;
	result = 0;
	index = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	while (str[index] != '\0')
	{
		result += (str[length - index - 1] - '0') * base;
		base *= 10;
		index++;
	}
	return (result);
}

int		*get_number_array(char **str_array, int word_count)
{
	int *result;
	int index;

	result = (int *)malloc(word_count * sizeof(int));
	index = 0;
	while (index < word_count)
	{
		result[index] = str_to_int(str_array[index]);
		index++;
	}
	return (result);
}

int		*fill_clue(char *str)
{
	int		index;
	int		number_count;
	char	**result_char;
	int		*result;

	index = -1;
	while (str[++index] != '\0')
	{
		if (is_space(str[index]) == 0 && is_numeric(str[index]) == 0)
		{
			print_error();
			return (0);
		}
	}
	number_count = get_number_count(str);
	result_char = get_number_word(str);
	result = get_number_array(result_char, number_count);
	index = 0;
	while (index < number_count)
	{
		free(result_char[index]);
		index++;
	}
	free(result_char);
	return (result);
}

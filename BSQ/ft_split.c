/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:29:46 by juan              #+#    #+#             */
/*   Updated: 2020/07/21 22:07:39 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_sep(char *charset, char c)
{
	while (*charset)
	{
		if (c == *charset)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}

int			get_word_cnt(char *str, char *charset)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(charset, str[i]))
		{
			cnt++;
			while (str[i] && !is_sep(charset, str[i]))
				i++;
		}
		i++;
	}
	return (cnt);
}

void		str_cpy_range(char *dest, char *src, int start, int end)
{
	int i;

	i = 0;
	while (src[i] && i < end - start)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void		put_str_to_array(char **res, char *str, char *charset, int *index)
{
	int		i;
	int		start;
	char	*element;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (!is_sep(charset, str[i]))
		{
			start = i;
			while (str[i] && !is_sep(charset, str[i]))
				i++;
			element = (char *)malloc((i - start + 1) * sizeof(char));
			str_cpy_range(element, str + start, start, i);
			res[(*index)++] = element;
		}
		i++;
	}
}

char		**ft_split(char *str, char *charset)
{
	int		word_count;
	int		index;
	char	**result;

	word_count = get_word_cnt(str, charset);
	result = (char **)malloc((word_count + 1) * sizeof(char*));
	if (!result)
		return (result);
	index = 0;
	put_str_to_array(result, str, charset, &index);
	result[index] = 0;
	return (result);
}

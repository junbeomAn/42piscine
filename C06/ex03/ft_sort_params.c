/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:33:56 by juan              #+#    #+#             */
/*   Updated: 2020/07/14 22:03:58 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len++);
}

int		ft_compare_asc(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 > *str2)
			return (1);
		else if (*str1 < *str2)
			return (0);
		str1++;
		str2++;
	}
	if (!*str2 && *str1)
		return (1);
	if (!*str1 && *str2)
		return (0);
	return (0);
}

void	insertion_sort(char **list, int n)
{
	int		i;
	int		j;
	char	*key;

	i = 2;
	while (i < n)
	{
		key = list[i];
		j = i - 1;
		while (j > 0 && (ft_compare_asc(list[j], key)))
		{
			list[j + 1] = list[j];
			j--;
		}
		list[j + 1] = key;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	insertion_sort(argv, argc);
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}

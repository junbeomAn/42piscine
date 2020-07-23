/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:20:35 by juan              #+#    #+#             */
/*   Updated: 2020/07/18 00:16:51 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*concat(char *strs[], int length, int size, char *sep)
{
	int		i;
	int		j;
	int		curr;
	char	*acc;

	i = 0;
	j = 0;
	curr = 0;
	acc = (char *)malloc((length + 1) * sizeof(char));
	acc[length] = '\0';
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			acc[curr++] = strs[i][j++];
		j = 0;
		if (curr < length)
		{
			while (sep[j])
				acc[curr++] = sep[j++];
		}
		i++;
	}
	return (acc);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int length;
	int i;

	i = 0;
	length = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		if (i != size - 1)
			length += ft_strlen(sep);
		i++;
	}
	return (concat(strs, length, size, sep));
}

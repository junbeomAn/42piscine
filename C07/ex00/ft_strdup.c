/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:16:15 by juan              #+#    #+#             */
/*   Updated: 2020/07/16 12:02:28 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cp_str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	cp_str = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		cp_str[i] = src[i];
		i++;
	}
	cp_str[i] = '\0';
	return (cp_str);
}

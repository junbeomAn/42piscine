/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:16:22 by juan              #+#    #+#             */
/*   Updated: 2020/07/16 12:14:07 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *range;
	int i;

	if (min >= max)
		return (0);
	range = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		range[i++] = min++;
	}
	return (range);
}

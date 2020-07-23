/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:17:48 by juan              #+#    #+#             */
/*   Updated: 2020/07/16 18:23:40 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *assign;
	int i;

	if (min >= max)
		return (0);
	assign = (int *)malloc(sizeof(int) * (max - min));
	if (!assign)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		assign[i] = min + i;
		i++;
	}
	*range = assign;
	return (max - min);
}

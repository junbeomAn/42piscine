/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:30:04 by juan              #+#    #+#             */
/*   Updated: 2020/07/05 17:47:08 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int *a;
	int *b;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < ((size - 1) - i))
		{
			a = tab + j;
			b = tab + j + 1;
			if (*a > *b)
			{
				swap(a, b);
			}
			j++;
		}
		i++;
	}
}

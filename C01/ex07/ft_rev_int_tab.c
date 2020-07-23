/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:31:49 by juan              #+#    #+#             */
/*   Updated: 2020/07/05 17:11:14 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int index;
	int *front;
	int *rear;

	index = 0;
	while (index < (size / 2))
	{
		front = &tab[index];
		rear = &tab[size - 1 - index];
		swap(front, rear);
		index += 1;
	}
}

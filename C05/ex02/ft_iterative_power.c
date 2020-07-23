/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:11:06 by juan              #+#    #+#             */
/*   Updated: 2020/07/14 20:26:17 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int res;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	res = 1;
	while (power--)
	{
		res *= nb;
	}
	return (res);
}

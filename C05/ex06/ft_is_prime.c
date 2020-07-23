/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 21:08:58 by juan              #+#    #+#             */
/*   Updated: 2020/07/14 20:27:45 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

int	ft_is_prime(int nb)
{
	int sqrt_nb;
	int i;

	if (nb < 2)
		return (0);
	sqrt_nb = ft_sqrt(nb);
	i = 2;
	while (i <= sqrt_nb)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}

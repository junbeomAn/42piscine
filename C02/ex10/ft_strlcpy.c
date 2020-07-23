/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:56:47 by juan              #+#    #+#             */
/*   Updated: 2020/07/07 17:13:45 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	i = 0;
	while (src[count])
	{
		if (1 < size && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		count++;
	}
	if (size == 0)
		return (count);
	dest[i] = '\0';
	return (count);
}

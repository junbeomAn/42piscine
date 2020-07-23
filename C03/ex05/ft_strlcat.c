/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 09:39:36 by juan              #+#    #+#             */
/*   Updated: 2020/07/11 08:43:59 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int cnt;
	unsigned int dst_len;

	cnt = 0;
	while (dest[cnt])
		cnt++;
	dst_len = cnt;
	while (*src && cnt + 1 < size)
	{
		dest[cnt] = *src;
		cnt++;
		src++;
	}
	dest[cnt] = '\0';
	while (*src)
	{
		cnt++;
		src++;
	}
	if (size > dst_len)
		return (cnt);
	else
		return (cnt - dst_len + size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 02:31:04 by juan              #+#    #+#             */
/*   Updated: 2020/07/08 08:36:03 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		recur_check(char *str, char *nd)
{
	if (!(*nd))
	{
		return (1);
	}
	else if (*nd != *str)
	{
		return (0);
	}
	else
	{
		return (recur_check(str + 1, nd + 1));
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (recur_check(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}

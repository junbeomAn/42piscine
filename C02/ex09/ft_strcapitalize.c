/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:28:48 by juan              #+#    #+#             */
/*   Updated: 2020/07/07 21:31:25 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_num(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

int		check_alphabet(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || check_num(c))
	{
		return (1);
	}
	return (0);
}

void	upper_case(char *str)
{
	if (!check_alphabet(*str))
		return ;
	if ('a' <= (*str) && (*str) <= 'z')
	{
		*str = *str - 32;
	}
}

void	lower_case(char *str)
{
	if (!check_alphabet(*str))
		return ;
	if ('A' <= (*str) && (*str) <= 'Z')
	{
		*str = *str + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 || (str[i] && str[i - 1] == ' '))
			upper_case(&(str[i]));
		else if (check_alphabet(str[i]) && !check_alphabet(str[i - 1]))
			upper_case(&(str[i]));
		else
			lower_case(&(str[i]));
		i++;
	}
	return (str);
}

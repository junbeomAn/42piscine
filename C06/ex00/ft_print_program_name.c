/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:29:34 by juan              #+#    #+#             */
/*   Updated: 2020/07/16 11:19:40 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*p_name;
	int		i;

	i = argc;
	p_name = argv[0];
	i = 0;
	while (p_name[i])
		i++;
	write(1, p_name, i);
	write(1, "\n", 1);
	return (0);
}

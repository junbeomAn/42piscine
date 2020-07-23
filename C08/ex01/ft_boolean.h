/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:04:38 by juan              #+#    #+#             */
/*   Updated: 2020/07/19 17:15:22 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_FT_BOOLEAN_H
# define INCLUDE_FT_BOOLEAN_H

# include <unistd.h>
# define EVEN even
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0
# define TRUE 1
# define FALSE 0

typedef int	t_bool;

int	even(int num)
{
	return (num % 2 ? FALSE : TRUE);
}

#endif

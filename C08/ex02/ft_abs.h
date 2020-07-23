/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 13:15:31 by juan              #+#    #+#             */
/*   Updated: 2020/07/18 14:26:31 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_FT_ABS_H
# define INCLUDE_FT_ABS_H

# define ABS abs

int	abs(int value)
{
	return (value >= 0 ? value : -value);
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:18:56 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 15:57:05 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_UTILS_H
# define INCLUDE_UTILS_H

int		is_space(char c);
int		is_numeric(char c);
char	*get_number(char *str, int *length);
int		get_number_count(char *str);
int		ft_div_four(int nb);

#endif

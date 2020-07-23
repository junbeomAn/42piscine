/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:19:22 by juan              #+#    #+#             */
/*   Updated: 2020/07/12 15:47:35 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_UTILS2_H
# define INCLUDE_UTILS2_H

char	*ft_cpstr(char *str, int length);
char	**get_number_word(char *str);
int		str_to_int(char *str);
int		*get_number_array(char **str_array, int word_count);
int		*fill_clue(char *str);

#endif

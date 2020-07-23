/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <wnsqja8744@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:54:43 by juan              #+#    #+#             */
/*   Updated: 2020/07/22 12:02:09 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_MAP_VALIDATOR_H
# define INCLUDE_MAP_VALIDATOR_H
#include "map_sign.h"

int ft_strlen(char *str);
int is_printable(char c);
int char_validation(char **map, t_sign *info);
int sign_validation(t_sign *info);
int rows_len_validation(char **map, t_sign *info);
int is_valid_rows_num(char **map);
int check_line_break(char *row);
void print_map_error();

#endif

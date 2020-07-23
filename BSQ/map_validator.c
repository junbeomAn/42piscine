#include "map_sign.h"
#include <unistd.h>

// string utils

int ft_strlen(char *str)
{
  int len;

  len = 0;
  while (*str && *str != '\n')
  {
    str++;
    len++;
  }
  return (len);
}

int is_printable(char c)
{
  if (' ' <= c && c <= '~')
    return (1);
  return (0);
}

int char_validation(char **map, t_sign *info)
{
  int i;
  int j;
  char c;

  i = 0;
  j = 0;
  while (i < info->row)
  {	
	j = 0;
    while (j < info->col)
    {
      if (!is_printable(map[i][j]))
        return (0);
	  if ((map[i][j] != info->f_sign) &&
          (map[i][j] != info->e_sign) && (map[i][j] != info->o_sign))
        return (0);
	  j++;
    }
	i++;
  }
  return (1);
}

int sign_validation(t_sign *info)
{
  if (!(info->f_sign) || !(info->o_sign) || !(info->e_sign))
    return (0);
  else if (!is_printable(info->f_sign) || !is_printable(info->o_sign) || !is_printable(info->e_sign))
    return (0);
  else if (info->f_sign == info->e_sign)
    return (0);
  else if (info->o_sign == info->e_sign)
    return (0);
  else if (info->f_sign == info->o_sign)
    return (0);
  return (1);
}

// array utils

int rows_len_validation(char **map, t_sign *info)
{
  int len;
  int i;

  len = info->col;
  i = 0;
   while (i < info->row)
  {
	if (len != ft_strlen(map[i]))
      return (0);
    i++;
  }
  return (1);
}

int is_valid_rows_num(char **map)
{
  if (!map[0])
    return (0);
  return (1);
}

int check_line_break(char *row)
{
  while (*row)
  {
    if (*row == '\n')
      return (1);
    row++;
  }
  return (0);
}

void print_map_error()
{
  write(2, "map error\n", 10);
}

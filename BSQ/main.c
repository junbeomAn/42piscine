#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_split.c"
#include "map_validator.h"


#include <stdio.h>

int g_info;
int **g_matrix;

int bsq(t_sign *info);

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_open_file(char *file)
{
	g_info = open(file, O_RDONLY);
	if (g_info == -1)
	{
		ft_putstr("Can't Open FILE\n");
		return (0);
	}
	return (1);
}

void move_to_second_line()
{
	int buf[1];
	int ret;

	ret = 0;
	while ((ret = read(g_info, buf, 1)))
	{
		if (*buf == '\n')
			break;
	}
}

void	assign_sign(t_sign *info, int count, char *buf)
{
	if (count == 0)
		info->e_sign = *buf;
	else if (count ==1)
		info->o_sign = *buf;
	else if (count == 2)
		info->f_sign = *buf;
}

int read_first_line(t_sign *info)
{
	char buf[1];
	int ret;
	int res;
	int count;

	ret = 0;
	count = 0;
	res = 0;
	while ((ret = read(g_info, buf, 1)))
	{
		if (*buf == '\n')
			break;
		if(*buf >= '0' && *buf <= '9')
				res = (res * 10 + (*buf - '0'));
		else
		{
			assign_sign(info, count, buf);
			count++;
		}
	}
	info->row = res;
	return (0);
}

int len_row()
{
	int len;
	int ret;
	int check;
	char buf[1];

	len = 0;
	check = 0;
	ret = 0;
	while ((ret = read(g_info, buf, 1)))
	{
		if (check == 1)
		{
			if (*buf == '\n')
				break;
			len++;
		}
		if (check == 0 && *buf == '\n')
			check = 1;
	}
	return (len);
}

void ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char **file_to_map(t_sign *info, char *filename)
{
	int i;
	int row;
	int col;
	char **map;
	char *buf;

	i = -1;
	row = info->row;
	col = info->col;
	if (!ft_open_file(filename))
			return (0);
	move_to_second_line();
	map = (char **)malloc(sizeof(char *) * row);
	while (++i < row)
	{
		buf = (char *)malloc(sizeof(char) * 1000);
		map[i] = (char *)malloc(sizeof(char) * (col + 1));
		read(g_info, buf, col + 1);
		ft_strncpy(map[i], buf, col);
		// free(buf);
	}
	close(g_info);
	return (map);
}

int convert_to_int_arr(char **map, t_sign *info)
{
	int i;
	int j;

	i = 0;
	if (!(g_matrix = (int **)malloc(sizeof(int *) * (info->row))))
		return (0);
	while (i < info->row)
	{
		if (!(g_matrix[i] = (int *)malloc(sizeof(int) * (info->col))))
			return (0);
		j = 0;
		while (j < info->col)
		{
			if (map[i][j] == info->e_sign)
				g_matrix[i][j] = 1;
			else if(map[i][j] == info->f_sign)
				g_matrix[i][j] = 2;
			else if(map[i][j] == info->o_sign)
				g_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int is_valid_map(char **map, t_sign *info)
{
	if (!rows_len_validation(map, info))
		return (0);
	if (!is_valid_rows_num(map))
		return (0);
	if (!char_validation(map, info))
		return (0);
	if (!sign_validation(info))
		return (0);
	return (1);
}

int	update_info(t_sign *info, char *filename)
{
	if (!ft_open_file(filename))
		return (0);
	read_first_line(info);
	info->col = len_row();
	close(g_info);
	return (1);
}

char	*input_filename()
{
	char *buf;
	int ret;
	char *in_filename;

	buf = (char *)malloc(sizeof(char)*10000);
	read(0, buf, 10000);
	return (buf);
}

void free_map(char **map, t_sign *info)
{
  int i;

  i = 0;
  while (i < info->row)
  {
    free(map[i++]);
  }
  free(map);
}

void free_g_matrix(t_sign *info)
{
	int i;

	i = 0;
	while (i < info->row)
	{
		free(g_matrix[i++]);
	}
	free(g_matrix);
}

int main(int argc, char **argv)
{
	char **map;
	t_sign *info;
	int	i;
	char **input_args;

	i = 0;
	if (argc == 1)
	{
		input_args = ft_split(input_filename()," ");
		argv = input_args;
		argc = 3;
	}
	while (++i < argc)
	{
		info = (t_sign *)malloc(sizeof(t_sign));
		if(!update_info(info, argv[i]))
			continue;
		map = file_to_map(info, argv[i]);
		if(!is_valid_map(map, info))
		{
			print_map_error();
			continue;
		}
		if (!convert_to_int_arr(map, info))
			return (0);
		bsq(info);
		// free_g_matrix(info);
		// free_map(map, info);
		// free(info);
	}
	return (0);
}

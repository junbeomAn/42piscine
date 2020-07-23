#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "map_sign.h"

int **g_dp;
int g_maxlen;
extern int **g_matrix;

int min(int a, int b)
{
  if (a < b)
    return (a);
  else
    return (b);
}

int max(int a, int b)
{
  if (a < b)
    return (b);
  else
    return (a);
}

void free_dp(t_sign *info)
{
  int i;

  i = 0;
  while (i < info->row)
  {
    free(g_dp[i]);
    i++;
  }
  free(g_dp);
}

void print_max_square(int *offset, t_sign *info)
{
  int i;
  int j;

  i = 0;
  while (i < info->row)
  {
    j = 0;
    while (j < info->col)
    {
      if ((offset[0] - g_maxlen + 1 <= i && i <= offset[0]) && (offset[1] - g_maxlen + 1 <= j && j <= offset[1]))
        write(1, &(info->f_sign), 1);
      else if (g_matrix[i][j] == 0)
        write(1, &(info->o_sign), 1);
      else
        write(1, &(info->e_sign), 1);
      j++;
    }
    i++;
    write(1, "\n", 1);
  }
}

void find_max_square(int *offset, t_sign *info)
{
  int i;
  int j;
  i = 0;
  while (++i < info->row)
  {
    j = 0;
    while (++j < info->col)
    {

      if (g_matrix[i][j] == 1)
      {
        g_dp[i][j] = min(g_dp[i - 1][j - 1], min(g_dp[i][j - 1], g_dp[i - 1][j])) + 1;
        if (g_dp[i][j] > g_maxlen)
        {
          offset[0] = i;
          offset[1] = j;
        }
        g_maxlen = max(g_dp[i][j], g_maxlen);
      }
      else
        g_dp[i][j] = 0;
    }
  }
}

int init_dp_first_row_col(t_sign *info)
{
  int i;

  i = 0;
  while (i < info->row)
  {
    if (!(g_dp[i] = (int *)malloc(sizeof(int) * info->col)))
      return (0);
    g_dp[i][0] = g_matrix[i][0];
    i++;
  }
  i = 0;
  while (i < info->col)
  {
    g_dp[0][i] = g_matrix[0][i];
    i++;
  }
  return (1);
}

void init_offset(int *offset)
{
  offset[0] = 0;
  offset[1] = 0;
}

int bsq(t_sign *info)
{
  int offset[2];

  g_dp = (int **)malloc(sizeof(int *) * info->row);
  if (!g_dp)
    return (0);
  if (!init_dp_first_row_col(info))
    return (0);
  g_maxlen = 0;
  init_offset(offset);

  find_max_square(offset, info);
  print_max_square(offset, info);
  // free_dp(info);
  return (1);
}


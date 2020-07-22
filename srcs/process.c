/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:00:05 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 22:29:54 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			fill_map(char **map)
{
	int i;
	int j;
	int x_index;
	int y_index;

	x_index = g_meta.x_index;
	y_index = g_meta.y_index;
	i = 0;
	while (i < g_meta.max)
	{
		j = 0;
		while (j < g_meta.max)
		{
			if (map[x_index - i][y_index - j] == g_meta.obstacle)
				break ;
			else
				map[x_index - i][y_index - j] = g_meta.full;
			j++;
		}
		i++;
	}
}

void			get_xy_index(void)
{
	int i;
	int j;
	int max;

	max = g_meta.max;
	i = 0;
	while (i < g_meta.x_size)
	{
		j = 0;
		while (j < g_meta.y_size)
		{
			if (g_arr[i][j] == g_meta.max)
			{
				g_meta.x_index = i;
				g_meta.y_index = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void			malloc_g_arr(void)
{
	int i;

	i = 0;
	if (!(g_arr = (int **)malloc(sizeof(int *) * g_meta.x_size)))
		return ;
	while (i < g_meta.x_size)
	{
		if (!(g_arr[i] = (int *)malloc(sizeof(int) * g_meta.y_size)))
			return ;
		i++;
	}
}

void			make_g_arr(char **map)
{
	int i;
	int j;

	i = 0;
	while (i < g_meta.x_size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == g_meta.obstacle)
				g_arr[i][j] = 0;
			else if (i == 0 || j == 0)
				g_arr[i][j] = 1;
			else
			{
				g_arr[i][j] =
					min(g_arr[i - 1][j],
							min(g_arr[i][j - 1], g_arr[i - 1][j - 1])) + 1;
				if (g_meta.max < g_arr[i][j])
					g_meta.max = g_arr[i][j];
			}
			j++;
		}
		i++;
	}
}

void			process(void)
{
	char	**new_map;
	int		i;

	i = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * (g_meta.x_size + 1))))
		return ;
	new_map[g_meta.x_size] = 0;
	while (i < g_meta.x_size)
	{
		if (!(new_map[i] = ft_strndup(g_map[i + 1], g_meta.y_size)))
			return ;
		i++;
	}
	malloc_g_arr();
	make_g_arr(new_map);
	get_xy_index();
	fill_map(new_map);
	print_arr(new_map);
	free_str(new_map);
	free_arr();
}

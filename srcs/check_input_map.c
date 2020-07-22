/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:00:11 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 22:29:32 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_first_line(void)
{
	int len;
	int i;
	int size;

	size = 0;
	init_struct();
	len = 0;
	while (g_map[0][len])
		len++;
	i = len - 1;
	if (i < 3)
		return (1);
	g_meta.full = g_map[0][i--];
	g_meta.obstacle = g_map[0][i--];
	g_meta.empty = g_map[0][i--];
	while (i >= 0)
	{
		if (!(g_map[0][i] >= '0' && g_map[0][i] <= '9'))
			return (1);
		i--;
	}
	g_meta.x_size = ft_atoi(g_map[0], len - 3);
	return (0);
}

int		check_row_column_count(int i, int j, int len)
{
	i = 1;
	while (g_map[1][g_meta.y_size] != '\0')
		g_meta.y_size += 1;
	while (i <= g_meta.x_size)
	{
		if (g_map[i] == NULL)
			return (1);
		len = 0;
		j = 0;
		while (g_map[i][j])
		{
			if ((g_map[i][j] != g_meta.empty)
					&& (g_map[i][j] != g_meta.obstacle))
				return (1);
			j++;
			len++;
		}
		if ((len == 0) || (g_meta.y_size != 0 && g_meta.y_size != len))
			return (1);
		i++;
	}
	if (i != (g_meta.x_size + 1) || g_map[i] != 0)
		return (1);
	return (0);
}

int		check_input_map(void)
{
	if (g_map[1] == NULL)
		return (1);
	if (check_first_line() == 1)
		return (1);
	if (check_row_column_count(1, 0, 0) == 1)
		return (1);
	if (g_meta.x_size == 0 || g_meta.y_size == 0)
		return (1);
	if (g_meta.empty == g_meta.obstacle
			|| g_meta.empty == g_meta.full || g_meta.obstacle == g_meta.empty)
		return (1);
	return (0);
}

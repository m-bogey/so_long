/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:48:35 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:48:37 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_begin_p(char **area, t_map *map)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (area[i])
	{
		j = 0;
		while (area[i][j])
		{
			if (area[i][j] == 'P')
			{
				map->pos_b[0] = j;
				map->pos_b[1] = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	create_path_f(char **area, ssize_t x, ssize_t y, t_map *map)
{
	if ((area[y][x] != 'C' && area[y][x] != '0' && area[y][x] != 'E'
		&& area[y][x] != 'P'))
		return ;
	if (area[y][x] == 'E')
	{
		area[y][x] = '1';
		return ;
	}
	else
		area[y][x] = 'F';
	create_path_f(area, x + 1, y, map);
	create_path_f(area, x - 1, y, map);
	create_path_f(area, x, y + 1, map);
	create_path_f(area, x, y - 1, map);
}

static void	check_valid_path(char **area, t_for_hook *h)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (area[y])
	{
		x = 0;
		while (area[y][x])
		{
			if (area[y][x] != '0' && area[y][x] != '1' && area[y][x] != 'F')
				exit_error("Path is invalided\n", h);
			x++;
		}
		y++;
	}
}

void	check_path(t_map *map, t_for_hook *h)
{
	pos_begin_p(map->area, map);
	create_path_f(map->area, map->pos_b[0], map->pos_b[1], map);
	check_valid_path(map->area, h);
}

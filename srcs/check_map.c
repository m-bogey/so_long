/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:48:24 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:48:28 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		check_dim(t_map *map, t_for_hook *h);
static void		check_char(t_map *map, t_for_hook *h);
static void		check_doublon(t_map *map, t_for_hook *h);
static void		check_walls(t_map *map, t_for_hook *h);

void	check_map(t_map *map, t_for_hook *h)
{
	check_dim(map, h);
	check_char(map, h);
	check_doublon(map, h);
	check_walls(map, h);
	check_path(map, h);
}

static void	check_dim(t_map *map, t_for_hook *h)
{
	ssize_t	y;

	y = 0;
	map->x = ft_strlen(map->area[0]);
	while (map->area[y])
	{
		if (map->x != (ssize_t)ft_strlen(map->area[y]))
			exit_error("Map not be rectangular\n", h);
		y++;
	}
}

static void	check_char(t_map *map, t_for_hook *h)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->area[y])
	{
		x = 0;
		while (map->area[y][x])
		{
			if (map->area[y][x] != '0' && map->area[y][x] != '1'
				&& map->area[y][x] != 'C' && map->area[y][x] != 'E'
				&& map->area[y][x] != 'P' && map->area[y][x] != '\n')
				exit_error("Bad characters", h);
			if (map->area[y][x] == 'C')
				map->nb_col++;
			x++;
		}
		y++;
	}
}

static void	check_doublon(t_map *map, t_for_hook *h)
{
	size_t		x;
	size_t		y;
	t_content	co;

	y = 0;
	co.c = 0;
	co.e = 0;
	co.p = 0;
	while (map->area[y])
	{
		x = 0;
		while (map->area[y][x])
		{
			if (map->area[y][x] == 'C')
				co.c++;
			if (map->area[y][x] == 'E')
				co.e++;
			if (map->area[y][x] == 'P')
				co.p++;
			x++;
		}
		y++;
	}
	if (co.c == 0 || co.e != 1 || co.p != 1)
		exit_error("Duplicates characters or no C/E/P", h);
}

static void	check_walls(t_map *map, t_for_hook *h)
{
	ssize_t	y;
	ssize_t	x;

	y = 0;
	while (map->area[y])
	{
		x = 0;
		while (map->area[y][x])
		{
			if ((y == 0 && map->area[y][x] != '1')
				|| (y == map->y - 1 && map->area[y][x] != '1')
				|| (x == 0 && map->area[y][x] != '1')
				|| (x == map->x - 1 && map->area[y][x] != '1'))
				exit_error("No closed by walls", h);
			x++;
		}
		y++;
	}
}

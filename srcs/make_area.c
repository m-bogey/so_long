/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:48:46 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:48:48 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	del_n_area(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->area[i])
	{
		j = 0;
		while (map->area[i][j])
		{
			if (map->area[i][j] == '\n')
			{
				map->area[i][j] = '\0';
				map->map[i][j] = '\0';
			}
			j++;
		}
		i++;
	}
}

void	make_area_bis(t_map *map, t_for_hook *h, char *ar)
{
	ssize_t	i;
	int		fd;

	i = 0;
	map->area = malloc(sizeof(char *) * (map->y + 1));
	if (map->area == NULL)
		exit_error("Malloc fail\n", h);
	map->area[map->y] = NULL;
	map->map = malloc(sizeof(char *) * (map->y + 1));
	if (map->map == NULL)
		exit_error("Malloc fail\n", h);
	map->map[map->y] = NULL;
	fd = open(ar, O_RDONLY);
	if (fd == -1)
		exit_error("Open file fail\n", h);
	while (i < map->y)
	{
		map->area[i] = get_next_line(fd);
		map->map[i] = ft_strdup(map->area[i]);
		if (map->area[i] == NULL || map->map[i] == NULL)
			exit_error("Malloc fail\n", h);
		i++;
	}
	close (fd);
}

void	init_area(t_map *map, char *ar, t_for_hook *h)
{
	int		fd;
	char	*line;

	map->y = 1;
	fd = open(ar, O_RDONLY);
	if (fd == -1)
		exit_error("Open file fail\n", h);
	line = get_next_line(fd);
	if (line == NULL)
		exit_error("Malloc fail\n", h);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->y++;
	}
	close(fd);
	make_area_bis(map, h, ar);
	del_n_area(map);
}

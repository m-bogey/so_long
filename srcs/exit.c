/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:19 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:49:21 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_tab(t_map *map)
{
	ssize_t	i;

	if (map->area != NULL)
	{
		i = 0;
		while (map->area[i])
		{
			free(map->area[i]);
			i++;
		}
		free(map->area);
	}
	if (map->area != NULL)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

static void	destroy_img(t_for_hook *h)
{
	if (h->img_h->img_col != NULL)
		mlx_destroy_image(h->mlx_h->mlx, h->img_h->img_col);
	if (h->img_h->img_wall != NULL)
		mlx_destroy_image(h->mlx_h->mlx, h->img_h->img_wall);
	if (h->img_h->img_exit != NULL)
		mlx_destroy_image(h->mlx_h->mlx, h->img_h->img_exit);
	if (h->img_h->img_player != NULL)
		mlx_destroy_image(h->mlx_h->mlx, h->img_h->img_player);
	if (h->img_h->img_floor != NULL)
		mlx_destroy_image(h->mlx_h->mlx, h->img_h->img_floor);
}

void	exit_error(char *str, t_for_hook *h)
{
	free_tab(h->map_h);
	if (h->mlx_h->mlx != NULL)
	{
		destroy_img(h);
		mlx_loop_end(h->mlx_h->mlx);
		mlx_destroy_window(h->mlx_h->mlx, h->mlx_h->mlx_win);
		mlx_destroy_display(h->mlx_h->mlx);
		free(h->mlx_h->mlx);
	}
	free(h);
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	exit_end_game(t_for_hook *h)
{
	free_tab(h->map_h);
	destroy_img(h);
	mlx_loop_end(h->mlx_h->mlx);
	mlx_destroy_window(h->mlx_h->mlx, h->mlx_h->mlx_win);
	mlx_destroy_display(h->mlx_h->mlx);
	free(h->mlx_h->mlx);
	free(h);
	exit(0);
}

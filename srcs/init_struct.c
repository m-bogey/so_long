/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:48:59 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:49:01 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map, t_mlx_data *m, t_img_game *img)
{
	map->area = NULL;
	map->map = NULL;
	map->nb_col = 0;
	map->nb_step = 0;
	m->mlx = NULL;
	m->mlx_win = NULL;
	img->img_player = NULL;
	img->img_floor = NULL;
	img->img_wall = NULL;
	img->img_col = NULL;
	img->img_exit = NULL;
}

t_for_hook	*init_for_hook(t_map *map, t_img_game *img, t_mlx_data *m)
{
	t_for_hook	*h;

	h = ft_calloc(1, sizeof(t_for_hook));
	h->map_h = map;
	h->img_h = img;
	h->mlx_h = m;
	return (h);
}

void	init_img_game(t_img_game *img, t_mlx_data *m, t_for_hook *h)
{
	img->path_player = "./asset/girl.xpm";
	img->path_floor = "./asset/floor.xpm";
	img->path_wall = "./asset/flower.xpm";
	img->path_col = "./asset/col.xpm";
	img->path_exit = "./asset/chaudron.xpm";
	img->img_player = mlx_xpm_file_to_image(m->mlx, img->path_player,
			&img->width, &img->height);
	if (img->img_player == NULL)
		exit_error("Fail init img player", h);
	img->img_floor = mlx_xpm_file_to_image(m->mlx, img->path_floor,
			&img->width, &img->height);
	if (img->img_floor == NULL)
		exit_error("Fail init img floor", h);
	img->img_wall = mlx_xpm_file_to_image(m->mlx, img->path_wall,
			&img->width, &img->height);
	if (img->img_wall == NULL)
		exit_error("Fail init img wall", h);
	img->img_col = mlx_xpm_file_to_image(m->mlx, img->path_col,
			&img->width, &img->height);
	if (img->img_col == NULL)
		exit_error("Fail init img col", h);
	img->img_exit = mlx_xpm_file_to_image(m->mlx, img->path_exit,
			&img->width, &img->height);
	if (img->img_exit == NULL)
		exit_error("Fail init img exit", h);
}

void	init_dp(t_display *dp)
{
	dp->o = 158;
	dp->i = 0;
	dp->j = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:49:08 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:49:10 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dp_ut(t_map *map, t_mlx_data *m, t_img_game *img, t_display *dp)
{
	if (map->map[dp->j][dp->i] == '0')
		mlx_put_image_to_window(m->mlx, m->mlx_win, img->img_floor,
			dp->i * dp->o, dp->j * dp->o);
	else if (map->map[dp->j][dp->i] == '1')
		mlx_put_image_to_window(m->mlx, m->mlx_win, img->img_wall,
			dp->i * dp->o, dp->j * dp->o);
	else if (map->map[dp->j][dp->i] == 'P')
		mlx_put_image_to_window(m->mlx, m->mlx_win, img->img_player,
			dp->i * dp->o, dp->j * dp->o);
	else if (map->map[dp->j][dp->i] == 'C')
		mlx_put_image_to_window(m->mlx, m->mlx_win, img->img_col,
			dp->i * dp->o, dp->j * dp->o);
	else if (map->map[dp->j][dp->i] == 'E')
		mlx_put_image_to_window(m->mlx, m->mlx_win, img->img_exit,
			dp->i * dp->o, dp->j * dp->o);
}

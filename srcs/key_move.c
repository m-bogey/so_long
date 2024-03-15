/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:10:01 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/10 19:10:04 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_right(int keycode, t_for_hook *h)
{
	if (keycode == 100
		&& h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0] + 1] != '1'
		&& (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0] + 1] != 'E'
		|| h->map_h->nb_col == 0))
	{
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_player,
			(h->map_h->pos_b[0] + 1) * 158, h->map_h->pos_b[1] * 158);
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_floor,
			(h->map_h->pos_b[0]) * 158, h->map_h->pos_b[1] * 158);
		h->map_h->pos_b[0] += 1;
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'C')
		{
			h->map_h->nb_col--;
			h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] = '0';
		}
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'E')
			exit_end_game(h);
		h->map_h->nb_step++;
		ft_printf("number of steps : %d\n", h->map_h->nb_step);
	}
}

void	key_left(int keycode, t_for_hook *h)
{
	if (keycode == 97
		&& h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0] - 1] != '1'
		&& (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0] - 1] != 'E'
		|| h->map_h->nb_col == 0))
	{
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_player,
			(h->map_h->pos_b[0] - 1) * 158, h->map_h->pos_b[1] * 158);
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_floor,
			(h->map_h->pos_b[0]) * 158, h->map_h->pos_b[1] * 158);
		h->map_h->pos_b[0] -= 1;
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'C')
		{
			h->map_h->nb_col--;
			h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] = '0';
		}
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'E')
			exit_end_game(h);
		h->map_h->nb_step++;
		ft_printf("number of steps : %d\n", h->map_h->nb_step);
	}
}

void	key_up(int keycode, t_for_hook *h)
{
	if (keycode == 119
		&& h->map_h->map[h->map_h->pos_b[1] - 1][h->map_h->pos_b[0]] != '1'
		&& (h->map_h->map[h->map_h->pos_b[1] - 1][h->map_h->pos_b[0]] != 'E'
		|| h->map_h->nb_col == 0))
	{
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_player,
			h->map_h->pos_b[0] * 158, (h->map_h->pos_b[1] - 1) * 158);
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_floor,
			(h->map_h->pos_b[0]) * 158, h->map_h->pos_b[1] * 158);
		h->map_h->pos_b[1] -= 1;
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'C')
		{
			h->map_h->nb_col--;
			h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] = '0';
		}
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'E')
			exit_end_game(h);
		h->map_h->nb_step++;
		ft_printf("number of steps : %d\n", h->map_h->nb_step);
	}
}

void	key_down(int keycode, t_for_hook *h)
{
	if (keycode == 115
		&& h->map_h->map[h->map_h->pos_b[1] + 1][h->map_h->pos_b[0]] != '1'
		&& (h->map_h->map[h->map_h->pos_b[1] + 1][h->map_h->pos_b[0]] != 'E'
		|| h->map_h->nb_col == 0))
	{
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_player,
			h->map_h->pos_b[0] * 158, (h->map_h->pos_b[1] + 1) * 158);
		mlx_put_image_to_window(h->mlx_h->mlx, h->mlx_h->mlx_win,
			h->img_h->img_floor,
			(h->map_h->pos_b[0]) * 158, h->map_h->pos_b[1] * 158);
		h->map_h->pos_b[1] += 1;
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'C')
		{
			h->map_h->nb_col--;
			h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] = '0';
		}
		h->map_h->nb_step++;
		ft_printf("number of steps : %d\n", h->map_h->nb_step);
		if (h->map_h->map[h->map_h->pos_b[1]][h->map_h->pos_b[0]] == 'E')
			exit_end_game(h);
	}
}

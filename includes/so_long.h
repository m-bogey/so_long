/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:48:42 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/10 19:48:45 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"

typedef struct s_img_game
{
	int		width;
	int		height;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_col;
	char	*path_player;
	char	*path_floor;
	char	*path_wall;
	char	*path_col;
	char	*path_exit;
}				t_img_game;

typedef struct s_map
{
	ssize_t		x;
	ssize_t		y;
	ssize_t		pos_b[2];
	ssize_t		nb_col;
	ssize_t		nb_step;
	char		**area;
	char		**map;
}				t_map;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx_data;

typedef struct s_for_hook
{
	t_mlx_data	*mlx_h;
	t_map		*map_h;
	t_img_game	*img_h;
}				t_for_hook;

typedef struct s_content
{
	int		c;
	int		e;
	int		p;
}				t_content;

typedef struct s_display
{
	int		o;
	int		i;
	int		j;
}				t_display;

void		init_struct(t_map *so_long_map, t_mlx_data *m, t_img_game *img);
t_for_hook	*init_for_hook(t_map *map, t_img_game *base_img, t_mlx_data *m);
void		init_area(t_map *so_long_map, char *ar, t_for_hook *h);
void		init_img_game(t_img_game *img, t_mlx_data *m, t_for_hook *h);
void		init_dp(t_display *dp);
void		dp_ut(t_map *map, t_mlx_data *m, t_img_game *img, t_display *dp);
void		check_map(t_map *map, t_for_hook *h);
void		exit_error(char *str, t_for_hook *h);
void		check_path(t_map *map, t_for_hook *h);
void		key_right(int keycode, t_for_hook *h);
void		key_left(int keycode, t_for_hook *h);
void		key_up(int keycode, t_for_hook *h);
void		key_down(int keycode, t_for_hook *h);
void		exit_end_game(t_for_hook *h);

#endif 

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
# include <math.h>
# include "mlx.h"
# include "libft.h"
// # include <sys/mman.h>
// #include "minilibx-linux/mlx_int.h"
// #include "minilibx-linux/mlx.h"

typedef struct s_img_game
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_col;
	// int		height;
	// int		width;
	char	*path_player;
	char	*path_floor;
	char	*path_wall;
	char	*path_col;
	char	*path_exit;
}				t_img_game;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

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

void	check_map(char *map, int fd, t_map *so_long);
size_t	ft_strlen_c(char *map, char c);
void	exit_error(int fd, char *str);
void	check_path(char *buf, t_map *so_long);
void	key_right(int keycode, t_for_hook *h);
void	key_left(int keycode, t_for_hook *h);
void	key_up(int keycode, t_for_hook *h);
void	key_down(int keycode, t_for_hook *h);

#endif 

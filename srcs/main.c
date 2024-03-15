/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbogey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:48:10 by mbogey            #+#    #+#             */
/*   Updated: 2024/03/15 13:48:12 by mbogey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(int argc, char **argv);
void	display_map(t_map *map, t_mlx_data *m, t_img_game *img);
int		key_close(t_for_hook *h);
int		key_test_touch(int keycode, t_for_hook *h);

int	main(int argc, char **argv)
{
	t_for_hook	*h;
	t_mlx_data	m;
	t_img_game	img;
	t_map		map;

	check_argv(argc, argv);
	h = init_for_hook(&map, &img, &m);
	init_struct(&map, &m, &img);
	init_area(&map, argv[1], h);
	check_map(&map, h);
	m.mlx = mlx_init();
	if (m.mlx == NULL)
		exit_error("Fail init mlx", h);
	m.mlx_win = mlx_new_window(m.mlx, map.x * 158, map.y * 158, "Eternal Sleep");
	if (m.mlx_win == NULL)
		exit_error("Fail init mlx win", h);
	init_img_game(&img, &m, h);
	display_map(&map, &m, &img);
	mlx_hook(m.mlx_win, 17, 0, key_close, h);
	mlx_hook(m.mlx_win, 2, 1L << 0, key_test_touch, h);
	mlx_loop(m.mlx);
}

void	check_argv(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "not the right number of arguments\n", 34);
		exit(0);
	}
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b'
		|| argv[1][i - 4] != '.')
	{
		write(1, "file not ending with the .ber extension.\n", 41);
		exit(0);
	}
}

void	display_map(t_map *map, t_mlx_data *m, t_img_game *img)
{
	t_display	dp;

	init_dp(&dp);
	while (map->map[dp.j])
	{
		dp.i = 0;
		while (map->map[dp.j][dp.i])
		{
			dp_ut(map, m, img, &dp);
			dp.i++;
		}
		dp.j++;
	}
}

int	key_close(t_for_hook *h)
{
	exit_end_game(h);
	return (0);
}

int	key_test_touch(int keycode, t_for_hook *h)
{
	if (keycode == 65307)
		exit_end_game(h);
	key_right(keycode, h);
	key_left(keycode, h);
	key_up(keycode, h);
	key_down(keycode, h);
	return (0);
}

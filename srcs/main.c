#include "so_long.h"

t_for_hook	*init_for_hook(t_map *so_long_map, t_img_game *base_img, t_mlx_data *m);
void	init_img_game(t_img_game *img, t_mlx_data *m);
void	display_map(t_map *so_long_map, t_mlx_data *m, t_img_game *base_img);

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int	key_close(int *r)
{
	(void)r;
	exit(0);
	return (0);
}

int	key_test_touch(int keycode, t_for_hook *h)
{
	printf("nb col = %zu\n", h->map_h->nb_col);
	printf("%d %zu %zu\n", keycode, h->map_h->pos_b[0], h->map_h->pos_b[1]);
	if (keycode == 65307)
		exit(0);
	key_right(keycode, h);
	key_left(keycode, h);
	key_up(keycode, h);
	key_down(keycode, h);
	return (0);
}



int	main(void)
{
	t_for_hook	*h;
	t_mlx_data	m;
//	t_data	img;
	t_img_game	base_img;
	char		buf[1000];
	int			fd;
	int			size;
	t_map		so_long_map;

	so_long_map.nb_step = 0;

	fd = open("lvl.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	size = read(fd, buf, 127);
	buf[size] = 0;
	check_map(buf, fd, &so_long_map);
	m.mlx = mlx_init();
	m.mlx_win = mlx_new_window(m.mlx, 1920, 1080, "Eternal Sleep");
	//img.img = mlx_new_image(m.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	h = init_for_hook(&so_long_map, &base_img, &m);
	init_img_game(&base_img, &m);
	display_map(&so_long_map, &m, &base_img);
	int i;
	printf("----------- %zu %zu ---------", so_long_map.pos_b[0], so_long_map.pos_b[1]);
	mlx_hook(m.mlx_win, 17, 0, key_close, &i);// permet d'obtenir la croix pour fermer
	mlx_hook(m.mlx_win, 2, 1L << 0, key_test_touch, h);
	mlx_loop(m.mlx);
	close(fd);
	mlx_clear_window(m.mlx, m.mlx_win);
	mlx_destroy_window(m.mlx, m.mlx_win);
}

t_for_hook	*init_for_hook(t_map *so_long_map, t_img_game *base_img, t_mlx_data *m)
{
	t_for_hook	*h;

	h = ft_calloc(1, sizeof(t_for_hook));
	h->map_h = so_long_map;
	h->img_h = base_img;
	h->mlx_h = m;

	return (h);
}

void	init_img_game(t_img_game *img, t_mlx_data *m)
{
	int		img_width;
	int		img_height;

	img->path_player = "./asset/enemy.xpm";
	img->path_floor = "./asset/floor.xpm";
	img->path_wall = "./asset/wall.xpm";
	img->path_col = "./asset/col.xpm";
	img->path_exit = "./asset/exit.xpm";
	img->img_player = mlx_xpm_file_to_image(m->mlx, img->path_player, &img_width, &img_height);
	img->img_floor = mlx_xpm_file_to_image(m->mlx, img->path_floor, &img_width, &img_height);
	img->img_wall = mlx_xpm_file_to_image(m->mlx, img->path_wall, &img_width, &img_height);
	img->img_col = mlx_xpm_file_to_image(m->mlx, img->path_col, &img_width, &img_height);
	img->img_exit = mlx_xpm_file_to_image(m->mlx, img->path_exit, &img_width, &img_height);
}

void	display_map(t_map *so_long_map, t_mlx_data *m, t_img_game *base_img)
{
	int o = 32;
	int i = 0;
	int j = 0;
	while (so_long_map->map[j])
	{
		i = 0;
		while (so_long_map->map[j][i])
		{
			if (so_long_map->map[j][i] == '0')
				mlx_put_image_to_window(m->mlx, m->mlx_win, base_img->img_floor, i * o, j * o);
			else if (so_long_map->map[j][i] == '1')
				mlx_put_image_to_window(m->mlx, m->mlx_win, base_img->img_wall, i * o, j * o);
			else if (so_long_map->map[j][i] == 'P')
				mlx_put_image_to_window(m->mlx, m->mlx_win, base_img->img_player, i * o, j * o);
			else if (so_long_map->map[j][i] == 'C')
				mlx_put_image_to_window(m->mlx, m->mlx_win, base_img->img_col, i * o, j * o);
			else if (so_long_map->map[j][i] == 'E')
			 	mlx_put_image_to_window(m->mlx, m->mlx_win, base_img->img_exit, i * o, j * o);
			i++;
		}
		j++;
	}
}
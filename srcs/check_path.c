#include "so_long.h"

void    make_area(char *buf, t_map *so_long)
{
    ssize_t    i;
    ssize_t    k;
    ssize_t    j;

    i = 0;
    j = 0;
    so_long->map = malloc(sizeof(char *) * (so_long->y + 1));
    //if (area == NULL)
    //    exit_error(fd, "Fail malloc area");
    so_long->area = malloc(sizeof(char *) * (so_long->y + 1));
    so_long->map[so_long->y] = NULL;
    so_long->area[so_long->y] = NULL;
    while (i < so_long->y)
    {
        k = 0;
        so_long->map[i] = malloc(sizeof (char) * so_long->x);
        so_long->area[i] = malloc(sizeof (char) * so_long->x);
        while (buf[j] && buf[j] != '\n')
        {
            so_long->map[i][k] = buf[j];
            so_long->area[i][k] = buf[j];
            j++;
            k++;
        }
        so_long->map[i][k] = '\0';
        so_long->area[i][k] = '\0';
        j++;
        i++;
    }
}

void    pos_begin_P(char **area, t_map *so_long)
{
    ssize_t    i;
    ssize_t    j;

    i = 0;
    while(area[i])
    {
        j = 0;
        while(area[i][j])
        {
            if (area[i][j] == 'P')
            {
                so_long->pos_b[0] = j;
                so_long->pos_b[1] = i;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    flood_file(char **area, ssize_t x, ssize_t y, t_map *so_long)
{
    if (x > so_long->x || x < 0 || y > so_long->y || y < 0 || (area[y][x] != 'C' && area[y][x] != '0' && area[y][x] != 'E' && area[y][x] != 'P'))
        return ;
    area[y][x] = 'F';
    flood_file(area, x + 1, y, so_long);
    flood_file(area, x - 1, y, so_long);
    flood_file(area, x, y + 1, so_long);
    flood_file(area, x, y - 1, so_long);
}


void    check_path(char *buf, t_map *so_long) 
{
    make_area(buf, so_long);
   	pos_begin_P(so_long->area, so_long);
    flood_file(so_long->area, so_long->pos_b[0], so_long->pos_b[1], so_long);
    for (int i = 0;so_long->map[i];i++)
        printf("%s\n", so_long->map[i]);
    printf("\n\n");
	for (int q = 0;so_long->area[q];q++)
        printf("%s\n", so_long->area[q]);
    //ft_free_tab(test_path);
}

// int main()
// {
//     int fd;
//     int size;
//     char buf[1000];
// 	t_map	so_long;

// 	so_long.x = 8;
// 	so_long.y = 8;
//     fd = open("lvl.ber", O_RDONLY);
//     size = read(fd, buf, 1000);
// 	//make_area(buf, &so_long);
// 	check_path(buf, &so_long);
// //	for(int i = 0;so_long.area[i];i++)
//   //  	printf("%s\n", so_long.area[i]);
// }
#include "libft.h"

int	main(void)
{
	char	buf[1000];
	int		fd;
	int		size;

	fd = open("lvl.ber", O_RDONLY);
	if (fd == -1)
		return 1;
	size = read(fd, buf, 127);
	buf[size] = 0;
	if (check_map(buf) < 0)
		return (0);

	close(fd);
	// ouvrir une fenetre
	// insert perso avec deplacement 
	//inserer la carte et gerer collision/fin de partie/ect
}

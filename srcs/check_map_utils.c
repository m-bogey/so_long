#include "so_long.h"

void	exit_error(int fd, char *str)
{
	//(void)str;
	write(2, "Error\n", 6);
	write(2, str, ft_strlen_c(str, '\0'));
	ft_putstr_fd(str, 2);
	close(fd);
	exit(EXIT_FAILURE);
}
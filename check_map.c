#include "libft.h"

static size_t	ft_strlen(char* map, char c);
static int		check_dim(char* map);
static int		check_char(char* map, size_t x, size_t y, size_t total);

int	check_map(char *map)
{
	int err;

	err = check_dim(map);
	if (err == -2)
	{
		write(1, "Error\nwrong map size", 20);
		return(0);
	}
	if (err == -3)
	{
		write(1, "Error\nthe map must not be square", 32);
		return(0);
	}
	//ve 01CEP
	//ve P = 1; E = 1; C >= 1   message d'erreur si doublon
	//ve si 1 autour
	//ve chemin valide
	printf("\n%s",map);
	return 0;
}

static int	check_dim(char* map)
{
	size_t	total;
	size_t	x;
	size_t	y;

	total = ft_strlen(map, '\0');
	x = ft_strlen(map, '\n') + 1;
	y = total / x;
	//verifier dimension rectangulaire
	if (total % x != 0)
		return (-2);
	if (y == x)
		return (-3);
	check_char(map, x, y, total);
}

static int	check_char(char* map, size_t x, size_t y, size_t total)
{
	size_t i;
	size_t lastln;

	lastln = total - x;
	i = 0;
	//todo a refaireee marche pas
	while (map[i] == '0' || map[i] == '1' || map[i] == 'C' || map[i] == 'E' || map[i] == 'P' || map[i] == '\n')
	{
		if ((i < x - 1 && map[i] != '1') && (i > lastln && map[i] != '1'))
		{
			write(1, "Error\ndifferente char than 1", 28);
			return (-1);
		}
		if (map[i] != '1' && map[i + 1] == '\n')
		{
			write(1, "Error\ndifferente char than 1sg", 28);
			return (-1);
		}
		i++;
	}
	if (i != total)
	{
		write(1, "Error\ndifferente char than 01CEP", 32);
		return (-1);
	}
}

static size_t	ft_strlen(char* map, char c)
{
	size_t	i;
	
	i = 0;
	while (map[i] != c)
		i++;
	return (i);
}

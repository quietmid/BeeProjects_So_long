// #include "so_long.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	check_map_content(char *map)
{
	int	i;

	int chest = 0;
	int exit = 0;
	int player = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			chest++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != '\n')
			printf("Invalid Map, wrong input %i\n", i);
	}
	if (map[i] == '\0' && exit == 1 && player == 1 && chest >= 1)
		printf("Success map\n");
	else
		printf("Invalid Map, it is missing key details\n");
}

int	main()
{
	char *str = "11111\n10001\n10101\n101C1\n1E1P1\n11C11";

	check_map_content(str);
	return (0);
}
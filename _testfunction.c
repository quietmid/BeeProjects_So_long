#include "so_long.h"

void	check_map_content(char *map, t_game *game)
{
	int	i;

	int chest = 0;
	int exit = 0;
	int player = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'E')
			exit++;
		else if (map[i] == 'C')
			chest++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != '\n')
			printf("Invalid Map, wrong input %i\n", i);
		i++;
	}
	if (exit != 1 || player != 1 || chest < 1)
		printf("Invalid Map, not enough\n");
	else
		printf("Success map\n");
}

int	main()
{
	char *str = "111111PCE11111\n111111\n111111\n";
	t_game	*game;

	check_map_content(str, game);
	return (0);
}
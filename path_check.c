/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:04:21 by jlu               #+#    #+#             */
/*   Updated: 2024/01/19 14:14:20 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, size_t height)
{
	size_t i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_path(t_game *temp, size_t y, size_t x)
{
	if (temp->map[y][x] == '1')
		return (0);
	if (temp->map[y][x] == 'C')
		temp->chest--;
	if (temp->map[y][x] == 'E')
	{
		temp->exit = 1;
		return (0);
	}
	temp->map[y][x] = '1';
	if (check_path(temp, y + 1, x))
		return (1);
	if (check_path(temp, y - 1, x))
		return (1);
	if (check_path(temp, y, x + 1))
		return (1);
	if (check_path(temp, y, x - 1))
		return (1);
	return (0);
}

void	temp_map(t_game *game)
{
	t_game	temp;
	size_t	i;

	temp.height = game->height;
	temp.width = game->width;
	temp.chest = game->chest;
	temp.player_x = game->player_x;
	temp.player_y = game->player_y;
	temp.exit = 0;
	temp.map = (char **)malloc(temp.height * sizeof(char *));
	if (!temp.map)
		error_msg_params("Memory Allocation Failed");
	i = 0;
	while (i < temp.height)
	{
		temp.map[i] = ft_strdup(game->map[i]);
		i++;
	}
	check_path(&temp, temp.player_x, temp.player_y);
	if (!(temp.exit == 1 && temp.chest == 0))
		error_msg_params("No valid path available");
	free_map(temp.map, temp.height);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:48:51 by jlu               #+#    #+#             */
/*   Updated: 2024/02/03 19:15:46 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_chests(t_game *game)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

size_t	map_height(char **map)
{
	size_t	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	check_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || \
	c == 'E' || c == 'P' || c == 'B' || c == '\n')
		return (1);
	return (0);
}

size_t	get_player_pos(t_game *game, char c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				if (c == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

size_t	get_exit_pos(t_game *game, char c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
			{
				if (c == 'x')
					return (x);
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

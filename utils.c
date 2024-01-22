/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:56:01 by jlu               #+#    #+#             */
/*   Updated: 2024/01/22 16:46:45 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

// prints out the error msg and also free the array of map string
void	error_msg_params(char *msg)
{
	ft_putstr_fd("Error\n", 1);
	ft_putendl_fd(msg, 1);
	exit (1);
}

size_t	map_height(char **map)
{
	size_t y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

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

//int main(void)
//{
//	char	*map[5];

//	for (int i = 0; i < 5; i++) 
//	{
//  		map[i] = malloc(sizeof(char) * 100);
//  		if (!map[i]) 
//  		{
//    		return (0);
//  		}
//	}	

//// Assign string values to each element
//	for (int i = 0; i < 5; i++) 
//	{
//  		ft_strcpy(map[i], "aksjdflajfdlkj");
//	}
//	printf("%s\n", map[4]);
//	error_msg_params("Too many arg", map);
//	return (0);
//}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:16:13 by jlu               #+#    #+#             */
/*   Updated: 2024/02/02 14:42:16 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus_to_window(t_game *game)
{
	game->img->moves_print = mlx_put_string(game->mlx_ptr, "MOVES:", 27, 8);
	mlx_image_to_window(game->mlx_ptr, game->img->chest_open, 120, 1);
	mlx_put_string(game->mlx_ptr, ":", 152, 8);
}

void	count_moves_bonus(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	mlx_delete_image(game->mlx_ptr, game->img->moves_nbr);
	game->img->moves_nbr = mlx_put_string(game->mlx_ptr, str, 88, 8);
	free(str);
}

void	count_collected_bonus(t_game *game)
{
	char *count;

	count = ft_itoa(game->collected);
	mlx_delete_image(game->mlx_ptr, game->img->count);
	game->img->count = mlx_put_string(game->mlx_ptr, count, 165, 8);
	free(count);
	
}
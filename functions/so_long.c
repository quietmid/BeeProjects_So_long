/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:44 by jlu               #+#    #+#             */
/*   Updated: 2024/02/04 18:45:57 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
		return (0);
	return (1);
}

static void	terminate_game(t_game *game, t_img *images)
{
	free_map(game->map, game->height);
	free(game);
	free(images);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_img	*images;

	if (argc != 2)
		error_msg_params("Wrong number of arguments");
	if (is_ber(argv[1]) == 0)
		error_msg_params("Not a valid map file");
	game = check_map(argv[1]);
	if (!game)
		error_msg_params("Map failed");
	game->mlx_ptr = mlx_init(game->width * 32, \
	game->height * 32, "so_long", true);
	if (!game->mlx_ptr)
		return (EXIT_FAILURE);
	images = init_img_struct(game->mlx_ptr);
	game->img = images;
	fill_map(game);
	render_map(game);
	bonus_to_window(game);
	mlx_key_hook(game->mlx_ptr, move_hook, game);
	mlx_loop_hook(game->mlx_ptr, monster_patrol, game);
	mlx_loop(game->mlx_ptr);
	mlx_terminate(game->mlx_ptr);
	terminate_game(game, images);
	return (EXIT_SUCCESS);
}

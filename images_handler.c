/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:59:01 by jlu               #+#    #+#             */
/*   Updated: 2024/01/23 14:57:48 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_wall_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/walls/boarder.png");
	if (!wall)
		error_msg_params("Problem with png loading");
	img->wall = mlx_texture_to_image(mlx_ptr, wall);
	if (!img->wall)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(wall);
	return (img);
}

t_img	*load_floor_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./assets/floor/floor.png");
	if (!floor)
		error_msg_params("Problem with png loading");
	img->floor = mlx_texture_to_image(mlx_ptr, floor);
	if (!img->floor)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(floor);
	return (img);
}

t_img	*load_chestcl_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*chest_closed;

	chest_closed = mlx_load_png("./assets/Chest/chest_closed_anim_f0.png");
	if (!chest_closed)
		error_msg_params("Problem with png loading");
	img->chest_closed = mlx_texture_to_image(mlx_ptr, chest_closed);
	if (!img->chest_closed)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(chest_closed);
	return (img);
}

t_img	*load_chestop_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*chest_open;

	chest_open = mlx_load_png("./assets/Chest/chest_open.png");
	if (!chest_open)
		error_msg_params("Problem with png loading");
	img->chest_open = mlx_texture_to_image(mlx_ptr, chest_open);
	if (!img->chest_open)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(chest_open);
	return (img);
}

t_img	*load_exitclosed_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*exit_closed;

	exit_closed = mlx_load_png("./assets/Exit/door_anim_opening_f7.png");
	if (!exit_closed)
		error_msg_params("Problem with png loading");
	img->exit_closed = mlx_texture_to_image(mlx_ptr, exit_closed);
	if (!img->exit_closed)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(exit_closed);
	return (img);
}

t_img	*load_exitopen_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*exit_open;

	exit_open = mlx_load_png("./assets/Exit/door_anim_opening_f10.png");
	if (!exit_open)
		error_msg_params("Problem with png loading");
	img->exit_open = mlx_texture_to_image(mlx_ptr, exit_open);
	if (!img->exit_open)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(exit_open);
	return (img);
}

t_img	*load_monster_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*monster_r;
	mlx_texture_t	*monster_l;

	monster_r = mlx_load_png("./assets/enemy/goblin_Right.png");
	if (!monster_r)
		error_msg_params("Problem with png loading");
	img->monster_right = mlx_texture_to_image(mlx_ptr, monster_r);
	if (!img->monster_right)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(monster_r);
	monster_l = mlx_load_png("./assets/enemy/goblin_Left.png");
	if (!monster_l)
		error_msg_params("Problem with png loading");
	img->monster_left = mlx_texture_to_image(mlx_ptr, monster_l);
	if (!img->monster_left)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(monster_l);
	return (img);
}

t_img	*load_player_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/hero/Hero.png");
	if (!player)
		error_msg_params("Problem with png loading");
	img->player = mlx_texture_to_image(mlx_ptr, player);
	if (!img->player)
		error_msg_params("Problem with texture to image");
	mlx_delete_texture(player);
	return (img);
}


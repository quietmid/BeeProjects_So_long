/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_handler2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:59:01 by jlu               #+#    #+#             */
/*   Updated: 2024/01/31 16:11:00 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// load exit_open, monster and player

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

t_img	*load_playerrnl_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player_right;
	mlx_texture_t	*player_left;

	player_right = mlx_load_png("./assets/hero/Walk_Right.png");
	if (!player_right)
		error_msg_params("Problem with png loading");
	img->player_right = mlx_texture_to_image(mlx_ptr, player_right);
	if (!img->player_right)
		error_msg_params("Problem with texture to image_player_right");
	mlx_delete_texture(player_right);
	player_left = mlx_load_png("./assets/hero/Walk_Left.png");
	if (!player_left)
		error_msg_params("Problem with png loading");
	img->player_left = mlx_texture_to_image(mlx_ptr, player_left);
	if (!img->player_left)
		error_msg_params("Problem with texture to image_player_left");
	mlx_delete_texture(player_left);
	return (img);
}

t_img	*load_playerund_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_down;

	player_up = mlx_load_png("./assets/hero/Walk_Up.png");
	if (!player_up)
		error_msg_params("Problem with png loading");
	img->player_up = mlx_texture_to_image(mlx_ptr, player_up);
	if (!img->player_up)
		error_msg_params("Problem with texture to image_player_up");
	mlx_delete_texture(player_up);
	player_down = mlx_load_png("./assets/hero/Walk_Down.png");
	if (!player_down)
		error_msg_params("Problem with png loading");
	img->player_down = mlx_texture_to_image(mlx_ptr, player_down);
	if (!img->player_down)
		error_msg_params("Problem with texture to image_player_down");
	mlx_delete_texture(player_down);
	return (img);
}

t_img	*load_player_text(mlx_t *mlx_ptr, t_img *img)
{
	mlx_texture_t	*player;
	mlx_texture_t	*player_die;
	
	player = mlx_load_png("./assets/hero/Hero.png");
	if (!player)
		error_msg_params("Problem with Player png loading");
	img->player = mlx_texture_to_image(mlx_ptr, player);
	if (!img->player)
		error_msg_params("Problem with texture to image_just player");
	player_die = mlx_load_png("./assets/hero/Hero_die.png");
	if (!player_die)
		error_msg_params("Problem with Player_Dead png loading");
	img->player_die = mlx_texture_to_image(mlx_ptr, player_die);
	if (!img->player_die)
		error_msg_params("Problem with texture to image_just player");
	mlx_delete_texture(player);
	mlx_delete_texture(player_die);
	return(img);
}


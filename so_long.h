/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:24:39 by jlu               #+#    #+#             */
/*   Updated: 2024/01/13 19:18:54 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// library functions
# include "MLX42/include/MLX42/MLX42.h"
# include "lib/printf/ft_printf.h"
# include "lib/libft/libft.h"
# include "lib/get_next_line/get_next_line.h"

// C library
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_game
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*player_ptr; // the pointer for the player	
	void	*exit_ptr; // exit pointer
	void	*wall_ptr; // the wall pointer
	void	*chest_ptr;	// the chest pointer
	void	*monster_ptr; // the pointer for monster 
	char	**map; // the map pointer 2D array
	
}		t_game;

int	error_msg_params(char *msg, char **map_str);

#endif

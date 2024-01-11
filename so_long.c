/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:44 by jlu               #+#    #+#             */
/*   Updated: 2024/01/11 17:18:25 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (!(mlx_ptr = mlx_init(800, 600, "First Win", true)))
		return (EXIT_FAILURE);
	if(!(win_ptr = mlx_new_image(mlx_ptr, 800, 600)))
	{
		mlx_close_window(mlx_ptr);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx_ptr, win_ptr, 0, 0) == -1)
	{
		mlx_close_window(mlx_ptr);
		return (EXIT_FAILURE);
	}
	mlx_loop(mlx_ptr);
	mlx_terminate(mlx_ptr);
	return (0);
}	

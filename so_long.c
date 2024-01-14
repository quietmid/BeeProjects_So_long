/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:51:44 by jlu               #+#    #+#             */
/*   Updated: 2024/01/13 19:34:16 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* IT OPENS UP A WINDOW HERE!
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
*/
int	is_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (!(ft_strnstr(file, ".ber", len)))
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	char **map;

	map = NULL;
	if (argc != 2)
		error_msg_params("Only two arguments", map); // check for # arguments
	if (is_ber(argv[1]) == 0)
		error_msg_params("Not valid map file", map); // check map file
	map = parse_map(argv[1])// check and create map
}
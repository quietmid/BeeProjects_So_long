/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:56:01 by jlu               #+#    #+#             */
/*   Updated: 2024/01/13 19:18:17 by jlu              ###   ########.fr       */
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
int	error_msg_params(char *msg, char **map_str)
{
	if (map_str)
		free(*map_str);
	printf("Error: \n%s\n", msg); // need to link my ft_printf here
	exit (0);
	return (0);
}

int main(void)
{
	char	*map[5];

	for (int i = 0; i < 5; i++) 
	{
  		map[i] = malloc(sizeof(char) * 100);
  		if (!map[i]) 
  		{
    		return (0);
  		}
	}	

// Assign string values to each element
	for (int i = 0; i < 5; i++) 
	{
  		ft_strcpy(map[i], "aksjdflajfdlkj");
	}
	printf("%s\n", map[4]);
	error_msg_params("Too many arg", map);
	return (0);
}
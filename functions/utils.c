/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:56:01 by jlu               #+#    #+#             */
/*   Updated: 2024/01/25 19:00:52 by jlu              ###   ########.fr       */
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
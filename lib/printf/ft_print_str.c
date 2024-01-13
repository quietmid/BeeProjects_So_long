/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:49:30 by jlu               #+#    #+#             */
/*   Updated: 2023/11/24 14:25:14 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_print_str(char *str)
{
	int	len;

	if (str == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		len = 6;
		return (len);
	}
	len = ft_strlen(str);
	if (len > 0)
		if (write (1, &*str, len) == -1)
			return (-1);
	return (len);
}

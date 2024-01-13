/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:38:44 by jlu               #+#    #+#             */
/*   Updated: 2023/11/29 14:19:58 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr(unsigned long n, unsigned long base, char *symbols)
{
	int	count;
	int	temp;

	count = 0;
	temp = 0;
	if (n < base)
	{
		if (write (1, &symbols[n], 1) == -1)
			return (-1);
		count += 1;
	}
	else
	{
		temp = ft_get_ptr(n / base, base, symbols);
		if (temp == -1)
			return (-1);
		count += temp;
		temp = ft_get_ptr(n % base, base, symbols);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	return (count);
}

int	ft_print_ptr(unsigned long n, unsigned long base)
{
	int		count;
	int		temp;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	temp = 0;
	if (n == 0)
	{
		if (write (1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	temp = write (1, "0x", 2);
	if (temp == -1)
		return (-1);
	count += 2;
	temp = ft_get_ptr(n, base, symbols);
	if (temp == -1)
		return (-1);
	return (count += temp);
}

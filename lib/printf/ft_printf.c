/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:34 by jlu               #+#    #+#             */
/*   Updated: 2023/12/01 13:53:12 by jlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_format(char spec, va_list ap)
{
	int	temp;

	temp = 0;
	if (spec == 'c')
		temp = (ft_print_char(va_arg(ap, int)));
	else if (spec == 's')
		temp += ft_print_str(va_arg(ap, char *));
	else if (spec == 'p')
		temp += ft_print_ptr(va_arg(ap, unsigned long), 16);
	else if (spec == 'd' || spec == 'i')
		temp += ft_print_digit(va_arg(ap, int), 10);
	else if (spec == 'u')
		temp += ft_print_digit((unsigned)va_arg(ap, int), 10);
	else if (spec == 'x' || spec == 'X')
		temp += ft_print_hex(va_arg(ap, unsigned long), 16, spec);
	else
		temp = write (1, &spec, 1);
	if (temp == -1)
		return (-1);
	return (temp);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	if (!format || *format == '\0')
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		temp = 0;
		if (*format == '%' && (*(format + 1) != '\0'))
			temp = ft_eval_format(*(++format), ap);
		else if (*format != '%')
			temp = write (1, format, 1);
		++format;
		if (temp == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += temp;
	}
	va_end(ap);
	return (count);
}


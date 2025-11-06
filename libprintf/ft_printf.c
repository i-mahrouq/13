/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:46:06 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/06 17:44:04 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	size_t len;

	len = 0;
	i = 0;
	va_start(args, format);

	while (format[i]) {
		if (format[i] == '%' && format[i + 1] != '\0') {
			i++;
			if (format[i] == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (format[i] == 'p')
				len += ft_putptr(va_arg(args, void *));
			else if (format[i] == 'd' || format[i] == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (format[i] == 'u')
				len += ft_putunsigned(va_arg(args, unsigned int));
			else if (format[i] == 'x' || format[i] == 'X')
				len += ft_puthexa(va_arg(args, unsigned int), format[i]);
			else if (format[i] == '%')
				len += ft_putchar('%');
		}
		else
			len += ft_putchar(format[i]);
		if (len < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (len);
}


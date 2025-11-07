/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:46:06 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/07 23:41:49 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(va_list args, char specifier)
{
	int	ret;

	ret = 0;
	if (specifier == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		ret = ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		ret = ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		ret = ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		ret = ft_puthexa(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		ret = ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		ret;

	if (write(1, "", 0) == -1 || !format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (va_end(args), (-1));
			i++;
			ret = ft_handle_format(args, format[i]);
		}
		else
			ret = ft_putchar(format[i]);
		len += ret;
		i++;
	}
	return (va_end(args), len);
}

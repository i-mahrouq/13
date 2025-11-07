/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:46:42 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/06 17:46:16 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long n, char the_X)
{
	char	*hexa;
	int		len;
	int		ret;

	len = 0;
	if (the_X == 'x')
		hexa = "0123456789abcdef";
	else if (the_X == 'X')
		hexa = "0123456789ABCDEF";
	else
		return (0);
	if (n >= 16)
	{
		ret = ft_puthexa(n / 16, the_X);
		if (ret < 0)
			return (-1);
		len += ret;
	}
	ret = ft_putchar(hexa[n % 16]);
	if (ret < 0)
		return (-1);
	len += ret;
	return (len);
}

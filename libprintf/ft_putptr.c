/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:47:16 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/06 17:49:02 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					len;
	int					ret;

	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long long)ptr;
	ret = write(1, "0x", 2);
	if (ret < 0)
		return (-1);
	len += ret;
	ret = ft_puthexa(addr, 'x');
	if (ret < 0)
		return (-1);
	len += ret;
	return (len);
}

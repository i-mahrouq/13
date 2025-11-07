/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:46:56 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/06 17:46:57 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		len;
	int		ret;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		ret = ft_putchar('-');
		if (ret < 0)
			return (-1);
		len += ret;
		nb = -nb;
	}
	if (nb > 9)
	{
		ret = ft_putnbr(nb / 10);
		if (ret < 0)
			return (-1);
		len += ret;
	}
	ret = ft_putchar((nb % 10) + '0');
	if (ret < 0)
		return (-1);
	return (len + ret);
}

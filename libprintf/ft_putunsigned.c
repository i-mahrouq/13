/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:48:17 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/06 17:50:26 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	len;
	int	ret;

	len = 0;
	if (n > 9)
	{
		ret = ft_putunsigned(n / 10);
		if (ret < 0)
			return (-1);
		len += ret;
	}
	ret = ft_putchar('0' + (n % 10));
	if (ret < 0)
		return (-1);
	len += ret;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imahrouq <imahrouq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:46:01 by imahrouq          #+#    #+#             */
/*   Updated: 2025/11/06 15:53:05 by imahrouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long long n, char the_X);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int n);

#endif

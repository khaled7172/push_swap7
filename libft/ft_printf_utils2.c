/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 02:57:32 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/27 00:10:49 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(void *p)
{
	unsigned long	n;
	int				len;

	len = 0;
	n = (unsigned long)p;
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	len += 2;
	len += print_hex_helper(n);
	return (len);
}

int	print_hex_upper(unsigned int n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		len += print_hex_upper(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}

int	print_hex_helper(unsigned long n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += print_hex_helper(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 02:48:16 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/27 00:10:52 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	len = ft_strlen(s);
	return (len);
}

int	print_number(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		len++;
	}
	if (num >= 10)
		len += print_number(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
	len++;
	return (len);
}

int	print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += print_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	len++;
	return (len);
}

int	print_hex_lower(unsigned int n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += print_hex_lower(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:11:42 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/27 00:10:45 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_specifier(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_string(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int)));
	if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (print_hex_lower(va_arg(args, unsigned int)));
	if (c == 'X')
		return (print_hex_upper(va_arg(args, unsigned int)));
	if (c == 'p')
		return (print_ptr(va_arg(args, void *)));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			len += handle_specifier(format[i], args);
		}
		else
			len += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("%c %s %d %i %u %x %X %p %%\n",'A',"test",42,-42,42,42,42,&main);
// }

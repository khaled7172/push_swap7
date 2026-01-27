/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:27:05 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 23:33:27 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize - 1 && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (len);
}
// int	main (void)
// {
// 	char dst[100];
// 	char s[] = "hello";
// 	int a;
// 	a = ft_strlcpy(dst, s, 10);
// 	printf("%d", a);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:35:40 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 23:43:31 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	while (*dst)
		dst++;
	while (i < dstsize - len_dst - 1 && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (len_dst + len_src);
}

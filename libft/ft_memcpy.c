/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:29:36 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 20:24:45 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*s1;
	unsigned char		*s2;
	size_t				i;

	s1 = (unsigned const char *)src;
	s2 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*s2++ = *s1++;
		i++;
	}
	return (dst);
}
// int	main(void)
// {
// 	char s[10] = "abcdefghi";
// 	const char d[10] = "abcdefghi";
// 	void *ptr = ft_memcpy(s, d, 5);
// 	if (ptr)
// 		printf("success");
// }

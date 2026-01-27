/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:35:09 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 20:18:18 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			k;
	const unsigned char		*str;

	k = (unsigned char)c;
	str = (const unsigned char *)s;
	while (n--)
	{
		if (*str == k)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	const char s[10] = "abcdefghi";
// 	void *ptr = ft_memchr(s, 97, 5);
// 	if (ptr)
// 		printf("success");
// }

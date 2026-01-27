/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 05:32:55 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 21:31:48 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned const char	*s1;
	unsigned char		*s2;

	if (!dst || !src)
		return (NULL);
	s1 = (unsigned const char *)src;
	s2 = (unsigned char *)dst;
	if (s1 < s2)
	{
		while (n--)
		{
			s2[n] = s1[n];
		}
	}
	else
	{
		while (n--)
		{
			*s2++ = *s1++;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char str[] = "HelloWorld";
// 	ft_memmove(str+2, str, 5);
// 	printf("%s\n", str);
// }

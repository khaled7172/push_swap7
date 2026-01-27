/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:13:36 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 23:21:11 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	k;
	char			*ptr;

	k = (unsigned char)c;
	ptr = NULL;
	while (*s)
	{
		if (*s == k)
			ptr = (char *)s;
		s++;
	}
	if (*s == k)
		ptr = (char *)s;
	return (ptr);
}
// int	main(void)
// {
// 	char s[] = " hello man ";
// 	printf("%s", ft_strrchr(s, 97));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:49:59 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 23:39:02 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	k;

	k = (unsigned char) c;
	while (*s)
	{
		if (*s == k)
			return ((char *)s);
		s++;
	}
	if (k == '\0')
		return ((char *)s);
	return (NULL);
}
// int	main(void)
// {
// 	char s[] = " hellao man ";
// 	printf("%s", ft_strchr(s, 97));
// }

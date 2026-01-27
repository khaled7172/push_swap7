/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:51:47 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/14 12:53:56 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	char			*h;

	h = (char *)haystack;
	if (*needle == '\0')
		return (h);
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] && needle[j]
			&& h[i + j] == needle[j]
			&& (i + j) < len)
			j++;
		if (!needle[j])
			return (h + i);
		i++;
	}
	return (NULL);
}
// int	main (void)
// {
// 	char s[] = "hello man";
// 	char n[] = "man";
// 	printf("%s", ft_strnstr(s, n, 3));
// }

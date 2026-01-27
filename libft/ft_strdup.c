/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:32:04 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 23:37:57 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*str;
	char			*t;
	char			*start;
	int				len;

	str = (char *)s1;
	len = ft_strlen(str);
	t = malloc(sizeof(char) * (len + 1));
	start = t;
	if (!t)
		return (NULL);
	while (*str)
	{
		*t++ = *str++;
	}
	*t = '\0';
	return (start);
}
// int	main (void)
// {
// 	char s[] = "hello man";
// 	printf("%s", ft_strdup(s));
// }

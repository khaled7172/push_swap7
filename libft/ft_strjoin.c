/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:05:07 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 23:39:51 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	char	*joined;
	size_t	len2;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	start = joined;
	while (*s1)
	{
		*joined++ = *s1++;
	}
	while (*s2)
	{
		*joined++ = *s2++;
	}
	*joined = '\0';
	return (start);
}
// int	main (void)
// {
// 	char s[] = "hey";
// 	char d[] = "bye";
// 	printf("%s", ft_strjoin(s, d));
// }

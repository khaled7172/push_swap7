/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:23:50 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 19:50:56 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*start;
	size_t			i;

	start = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*start++ = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char s1[10] = "abcdefghi";
// 	ft_bzero(s1, 5);
// 	for (int i = 0; i < 10; i++)
// 		printf("%d", s1[i]);
// }

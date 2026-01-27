/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:12:30 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 21:37:56 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*start;
	unsigned char	value;

	start = (unsigned char *)b;
	value = (unsigned char)c;
	while (len--)
	{
		*start++ = value;
	}
	return (b);
}

// int	main (void)
// {
// 	char s[] = "abcdefghi";
// 	void *ptr = ft_memset(s, 3, 5);
// 	if(ptr)
// 		printf("success");
// }

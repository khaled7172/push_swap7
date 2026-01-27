/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:21:23 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 20:30:30 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
	{
		i++;
	}
	return (i);
}
// int	main(void)
// {
// 	int a;
// 	char s[] = "hello";
// 	a = ft_strlen(s);
// 	printf("%d", a);
// }

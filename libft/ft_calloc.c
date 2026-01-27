/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:02:51 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 20:01:49 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*array;

	if (count && size > (size_t) - 1 / count)
		return (NULL);
	array = malloc(count * size);
	if (!array)
		return (NULL);
	ft_memset(array, 0, count * size);
	return (array);
}
// int	main(void)
// {
// 	void *ptr = ft_calloc(1, sizeof(int));
// 	if (ptr)
// 		printf("success");
// }
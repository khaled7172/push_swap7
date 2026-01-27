/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:12:31 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/09 19:41:35 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const unsigned char	*conv;
	int					sign;
	int					res;

	sign = 1;
	res = 0;
	conv = (const unsigned char *)nptr;
	while (*conv == 32 || (*conv >= 9 && *conv <= 13))
		conv++;
	if (*conv == '-' || *conv == '+')
	{
		if (*conv == '-')
			sign = -1;
		conv++;
	}
	while (*conv >= '0' && *conv <= '9')
	{
		res = res * 10 + (*conv - '0');
		conv++;
	}
	res = res * sign;
	return (res);
}

// int	main(void)
// {
// 	const char s[] = "  -56";
// 	printf("%d", ft_atoi(s));
// }

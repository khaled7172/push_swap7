/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by kali              #+#    #+#             */
/*   Updated: 2026/02/01 00:53:18 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

int	total_ops(char *ops)
{
	int	count;
	int	i;

	if (!ops)
		return (0);
	count = 0;
	i = 0;
	while (ops[i])
	{
		if (ops[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	c_op(char *ops, char *op_name)
{
	int	count;
	int	i;
	int	len;

	if (!ops || !op_name)
		return (0);
	count = 0;
	i = 0;
	len = ft_strlen(op_name);
	while (ops[i])
	{
		if (ft_strncmp(&ops[i], op_name, len) == 0
			&& (ops[i + len] == '\n' || ops[i + len] == '\0'))
			count++;
		while (ops[i] && ops[i] != '\n')
			i++;
		if (ops[i])
			i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:56 by khhammou          #+#    #+#             */
/*   Updated: 2025/11/23 00:09:55 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;

	while (*lst)
	{
		curr = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = curr;
	}
	*lst = NULL;
}

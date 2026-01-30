/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 02:12:30 by khhammou          #+#    #+#             */
/*   Updated: 2026/01/30 02:12:32 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flags	parse_flags(int ac, char **av)
{
	t_flags	flags;
	int		i;
	int		strat;

	flags.strategy = ADAPTIVE;
	flags.bench = 0;
	flags.num_start = 1;
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		strat = check_flag(av[i]);
		if (strat != -1)
			flags.strategy = strat;
		else if (ft_strcmp(av[i], "--bench") == 0)
			flags.bench = 1;
		else
		{
			print_error();
			exit(1);
		}
		flags.num_start++;
		i++;
	}
	return (flags);
}

int	check_flag(char *str)
{
	if (ft_strcmp(str, "--simple") == 0)
		return (SIMPLE);
	else if (ft_strcmp(str, "--medium") == 0)
		return (MEDIUM);
	else if (ft_strcmp(str, "--complex") == 0)
		return (COMPLEX);
	else if (ft_strcmp(str, "--adaptive") == 0)
		return (ADAPTIVE);
	return (-1);
}

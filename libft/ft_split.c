/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:19:59 by khhammou          #+#    #+#             */
/*   Updated: 2025/12/19 20:33:00 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		array_creator(char **c, char *str, char sep);
static int		string_count(char *str, char sep);
char			**ft_split(const char *s, char c);

static void	array_creator(char **c, char *str, char sep)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			j = i;
			while (str[i] != sep && str[i])
				i++;
			c[k] = malloc((i - j + 1) * sizeof(char));
			l = 0;
			while (j < i)
				c[k][l++] = str[j++];
			c[k++][l] = '\0';
		}
		else
			i++;
	}
	c[k] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	str = malloc(sizeof(char *) * (string_count((char *)s, c) + 1));
	if (!str)
		return (NULL);
	array_creator(str, (char *)s, c);
	return (str);
}

static int	string_count(char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			while (str[i] != sep && str[i])
				i++;
			words++;
		}
		else
			i++;
	}
	return (words);
}

// int	main (void)
// {
// 	char s[] = "hell on earth";
// 	char **k = ft_split(s, ' ');
// 	int i = 0;
// 	while (k[i])
// 	{
// 		printf("word[%d]: '%s'\n", i, k[i]);
// 		i++;
// 	}
// }

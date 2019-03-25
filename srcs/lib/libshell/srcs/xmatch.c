/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:39:28 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 13:01:08 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

static int	get_sequence(char *matches, char **s2, int *i)
{
	if ((*((*s2) + 1) == '-') && (*((*s2) + 2) != ']'))
	{
		if (**s2 > *((*s2) + 2))
			return (0);
		while (**s2 < *((*s2) + 2))
		{
			matches[*i] = **s2;
			**s2 += 1;
			*i += 1;
		}
		*s2 += 2;
	}
	return (1);
}

static char	*get_matches(char **s2)
{
	char	*matches;
	int		i;

	i = 0;
	matches = (char *)malloc(sizeof(char) * 128);
	while (**s2 != ']')
	{
		if (!(get_sequence(matches, s2, &i)))
		{
			free(matches);
			return (NULL);
		}
		matches[i] = **s2;
		*s2 += 1;
		i++;
	}
	matches[i] = '\0';
	return (matches);
}

static int	match_in_brackets(char **s1, char **s2)
{
	char	*matches;
	int		rev;

	rev = 0;
	*s2 += 1;
	if (!ft_strchr(*s2, ']'))
		return (0);
	if (**s2 == '!')
	{
		*s2 += 1;
		rev = 1;
	}
	if (!(matches = get_matches(s2)))
		return (0);
	if ((!rev && ft_strchr(matches, **s1)) ||
							(rev && !ft_strchr(matches, **s1)))
	{
		*s1 += 1;
		*s2 += 1;
		free(matches);
		return (xmatch(*s1, *s2));
	}
	free(matches);
	return (0);
}

/*
** Search for the occurrence of the 's2' pattern in the 's1'
*/

int			xmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 != '*' && *s1 != '?' && *s1 == *s2)
		return (xmatch(s1 + 1, s2 + 1));
	else if (!*s1 && *s2 == '*')
		return (xmatch(s1, s2 + 1));
	else if (!*s1 && (*s2 == '?' || *s2 == '['))
		return (0);
	else if (*s1 && *s2 == '*')
		return (xmatch(s1, s2 + 1) || xmatch(s1 + 1, s2));
	else if (*s1 && *s2 == '?')
		return (xmatch(s1 + 1, s2 + 1));
	else if (*s1 && *s2 == '[')
		return (match_in_brackets(&s1, &s2));
	else
		return (0);
}

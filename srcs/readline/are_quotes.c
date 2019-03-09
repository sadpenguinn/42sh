/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 10:59:55 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 10:59:56 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void	set_single_quotes(int *single_quotes,
		int double_quotes, char c)
{
	if (c == '\'')
	{
		if (*single_quotes == 1)
			*single_quotes = 0;
		else if (double_quotes == 0)
			*single_quotes = 1;
	}
}

static void	set_double_quotes(int single_quotes,
		int *double_quotes, char c, int backslash)
{
	if (c == '"')
	{
		if (*double_quotes == 1)
		{
			if (backslash == 0)
				*double_quotes = 0;
		}
		else if (single_quotes == 0)
			*double_quotes = 1;
	}
}

int			are_quotes(char *buf, size_t len)
{
	size_t	i;
	int		single_quotes;
	int		double_quotes;
	int		backslash;

	single_quotes = 0;
	double_quotes = 0;
	i = 0;
	backslash = 0;
	while (i < len)
	{
		set_single_quotes(&single_quotes, double_quotes, buf[i]);
		set_double_quotes(single_quotes, &double_quotes, buf[i], backslash);
		set_backslash(buf, i, &backslash);
		i++;
	}
	return (double_quotes || single_quotes ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfa_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:22:03 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/08 18:22:04 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

extern int			g_state;
extern int			g_cnt;

static int			dfa_ret(int *i, int flag)
{
	flag == 1 ? g_cnt++ : g_cnt--;
	(*i)++;
	return (0);
}

int					dfa_check_state(char **str, int state, int *i)
{
	if (state == 94 || state == 100 || state == 104 || state == 106)
	{
		if ((*str)[*i] == '(')
			return (dfa_ret(i, 1));
		if ((*str)[*i] == ')' && g_cnt > 0)
			return (dfa_ret(i, 0));
	}
	if (state == 92 || state == 99)
	{
		if ((*str)[*i] == '[')
			return (dfa_ret(i, 1));
		if ((*str)[*i] == ']' && g_cnt > 0)
			return (dfa_ret(i, 0));
	}
	if (state == 98)
	{
		if ((*str)[*i] == '{')
			return (dfa_ret(i, 1));
		if ((*str)[*i] == '}' && g_cnt > 0)
			return (dfa_ret(i, 0));
	}
	return (1);
}

char				*dfa_push(char **str, char **string, int i)
{
	char	*lex;

	lex = push_symbol(string, *str, (size_t)i);
	*str = &((*str)[i]);
	return (lex);
}

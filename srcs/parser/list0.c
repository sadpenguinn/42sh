/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 22:33:15 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**      LST0(type:(AND | NEWLINE | SEMI)
**     /
** LST1
*/

#include "parser.h"

t_astree		*list0(void)
{
	int				type;
	t_astree		*res;
	t_astree		*root;

	if (!(res = list1()))
		return (0);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (freeastree(res));
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != NEWLINE && type != AND && type != SEMI)
		return (freeastree(res));
	g_curtok++;
	newline_list();
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	root->left = res;
	return (root);
}

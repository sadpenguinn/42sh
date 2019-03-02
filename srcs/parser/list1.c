/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/28 18:38:20 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**      /
**  LST2
**
**      LIST1
**     /    \
** LST2      SEMI
**          /    \
**      LST2      NEWLINE
**               /       \
**           LST2         ?SEMI
*/

#include "parser.h"

static t_astree	*list1_rest(void)
{
	t_type			type;
	t_astree		*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != NEWLINE && type != AND && type != SEMI)
		return (0);
	g_curtok++;
	newline_list();
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	if (!(root->left = list2()))
		return (root);
	root->right = list1_rest();
	return (root);
}

t_astree		*list1(void)
{
	t_astree		*root;
	t_astree		*res[2];

	if (!(res[0] = list2()))
		return (0);
	if (!(res[1] = list1_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = LIST1;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

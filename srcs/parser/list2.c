/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:06 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/15 15:18:21 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PLCM - Pipeline CoMmand
**	N - Null
**
**      /
**  PLCM
**
**      LIST2
**     /     \
** PLCM       OR_IF
**           /     \
**       PLCM       OR_IF
**                 /     \
**             PLCM       ...
*/

#include "parser.h"

static t_astree	*list2_rest(void)
{
	unsigned int	curtmp;
	t_astree		*root;

	curtmp = g_curtok;
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != OR_IF)
		return (0);
	g_curtok++;
	newline_list();
	root = xmalloc(sizeof(t_astree));
	root->type = OR_IF;
	if (!(root->left = list3()))
		return (savecur(curtmp), freeastree(root));
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (root);
	/* if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == OR_IF) */
		/* if (!(root->right = list2_rest())) */
			/* return (freeastree(root)); */
	root->right = list2_rest();
	return (root);
}

t_astree		*list2(void)
{
	t_astree		*root;
	t_astree		*res[2];

	if (!(res[0] = list3()))
		return (0);
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (res[0]);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != OR_IF)
		return (res[0]);
	if (!(res[1] = list2_rest()))
		/* return (res[0]); */
		return ((void)freeastree(res[0]), parseerror());
	root = xmalloc(sizeof(t_astree));
	root->type = LIST2;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

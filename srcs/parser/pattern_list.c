/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:26:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 20:11:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PATLST - PATtern LiST
**	PAT - PATtern
**	CPLST - ComPound LiST
**
**      PATLST
**     /      \
**  PAT        ?CPLST
*/

#include "parser.h"

t_astree	*pattern_list(void)
{
	unsigned int	curtmp;
	t_astree        *root;

	curtmp = g_curtok;
	root = xmalloc(sizeof(t_astree));
	newline_list();
	checktype(OBRACKET);
	if (!(root->left = pattern()))
		return (savecur(curtmp));
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type != CBRACKET)
		return (savecur(curtmp));
	g_curtok++;
	if (!(root->right = compound_list()))
		newline_list();
	return (root);
}

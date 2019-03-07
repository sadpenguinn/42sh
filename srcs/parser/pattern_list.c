/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:26:04 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
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
	t_astree		*root;

	curtmp = g_curtok;
	root = xmalloc(sizeof(t_astree));
	newline_list();
	checktype(OBRACKET);
	if (!(root->left = pattern()))
		return (savecur(curtmp, 0));
	if (!checktype(CBRACKET))
		return (savecur(curtmp, 0));
	if (!(root->right = compound_list()))
		newline_list();
	return (root);
}

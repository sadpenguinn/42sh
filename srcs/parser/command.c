/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:06:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 21:50:38 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
**                COMMAND
**    	    	 /       \
**           PREF         SUFF
**          /    \       /    \
**       ...      PREF         SUFF
**               /    \
**            ...      PREF
**                    /    \
**                 ...      ...
*/

#include "parser.h"

t_astree        *cmd_prefix_1(void)
{
	t_astree        *root;

	root = xmalloc(sizeof(t_astree));
	root->type = ASSIGMENT_WORD;
	root->content = ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	return (root);
}

t_astree        *cmd_prefix(void)
{
	t_astree	*root;
	t_astree	*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type ==
													ASSIGMENT_WORD)
		res = cmd_prefix_1();
	else
		res = io_redirect();
	if (!res)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	root->right = cmd_prefix();
	return (root);
}

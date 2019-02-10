/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:09:18 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 16:41:03 by bwerewol         ###   ########.fr       */
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
	t_lexem		*elem;
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	elem = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	/* XXX check word and not type */
	if (elem->type != ASSIGMENT_WORD)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = ASSIGMENT_WORD;
	root->content = ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	return (root);
}

t_astree        *cmd_prefix(void)
{
	unsigned int	curtmp;
	t_astree		*root;
	t_astree		*res;

	curtmp = g_curtok;
	if (!(res = cmd_prefix_1()))
		if (!(res = io_redirect()))
		{
			g_curtok = curtmp;
			return (0);
		}
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	root->right = cmd_prefix();
	return (root);
}


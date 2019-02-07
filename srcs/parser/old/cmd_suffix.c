/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:50:02 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 17:02:46 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                COMMAND
**    	    	 /       \
**           PREF         SUFF
**          /    \       /    \
**                    ...      SUFF
**                            /    \
**                         ...      SUFF
**                                 /    \
**                              ...      ...
*/

#include "parser.h"

t_astree        *cmd_suffix_1(void)
{
	t_astree        *root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WORD;
	root->content = ft_strdup(((t_lexem *)vector_get_elem(g_tokens, g_curtok++))->word);
	return (root);
}

t_astree        *cmd_suffix(void)
{
	unsigned int	curtmp;
	t_astree        *root;
	t_astree        *res;

	curtmp = g_curtok;
	if (!(res = io_redirect()))
		if (!(res = cmd_suffix_1()))
		{
			g_curtok = curtmp;
			return (0);
		}
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	root->right = cmd_suffix();
	return (root);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:39:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 16:25:14 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                PREF
**               /
**              <(type)
**             / \
**   (content)2   filename(content)
*/

#include "parser.h"

t_astree        *io_redirect_1(void)
{
	t_lexem		*elem;
	t_astree	*root;

	/* XXX check is_number */
	elem = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (elem->type != NUMBER)
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(elem->word);
	g_curtok++;
	return (root);

}

t_astree        *io_redirect(void)
{
	unsigned int	curtmp;
	t_astree		*root;
	t_astree		*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	curtmp = g_curtok;
	res = io_redirect_1();
	if (!(root = io_file()))
		if (!(root = io_here()))
		{
			g_curtok = curtmp;
			/* XXX Need free res and res->content */
			return (0);
		}
	root->left = res;
	return (root);
}

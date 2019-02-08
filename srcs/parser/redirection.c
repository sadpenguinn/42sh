/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:39:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/08 13:55:22 by bwerewol         ###   ########.fr       */
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

static t_astree        *get_io_number(void)
{
	t_lexem		*elem;
	t_astree	*root;

	elem = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	if (!check_redir_num(elem->word))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup(elem->word);
	g_curtok++;
	return (root);

}

t_astree        *redirection(void)
{
	unsigned int	curtmp;
	t_astree		*root;
	t_astree		*res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	curtmp = g_curtok;
	res = get_io_number();
	if (!(root = io_file()))
		if (!(root = io_here()))
			return (savecur(curtmp), freeastree(res));
	root->left = res;
	return (root);
}

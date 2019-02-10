/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:42:15 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 14:25:53 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                PREF
**               /
**              <(type)
**             /  \
**   (content)2    filename(content)
*/

#include "parser.h"

t_astree        *io_file(void)
{
	int				type;
	t_astree        *root;
	t_astree        *res;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type != LESS && type != LESSAND &&
		type != GREAT && type != GREATAND &&
		type != DGREAT && type != LESSGREAT && type != CLOBBER)
		return (0);
	g_curtok++;
	if (!(res = filename()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = type;
	root->right = res;
	return (root);
}


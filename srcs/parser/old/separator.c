/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:08:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 17:26:30 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**     \            /
**      SEPARATOR_OP(type:'&' | ';' | 0)
*/

#include "parser.h"

t_astree	*separator(void)
{
	t_astree	*root;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	if (((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type == NEWLINE)
		root = newline_list();
	else
	{
		root = separator_op();
		linebreak();
	}
	return (root);
}

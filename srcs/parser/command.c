/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:02:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 16:00:35 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
**     CMDREDIR
**    /        \
** CMD          REDIR
*/

static t_astree	*get_shell_command(void)
{
	t_astree	*res[2];
	t_astree	*root;

	if (!(res[0] = shell_command()))
		return (0);
	if (!(res[1] = redirection_list()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = CMDREDIR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

t_astree	*command(void)
{
	t_type			type;
	t_astree        *res;

/* printf("in command\n"); */
	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == DO || type == DONE || type == IN || type == THEN ||
		type == FI || type == ESAC || type == ELSE || type == ELIF)
		return (0);
	if (!g_parseerr && (res = function_def()))
		return (res);
	if (!g_parseerr && (res = get_shell_command()))
		return (res);
	if (!g_parseerr && (res = simple_command()))
		return (res);
	return (0);
}

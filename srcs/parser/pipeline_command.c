/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:05:30 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/10 21:52:43 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**      PIPECMD
**     /
** PIPE
**
**              NOT
**             /
**      PIPECMD
**     /
** PIPE
*/

#include "parser.h"

static t_astree	*get_pipline_bang(void)
{
	t_astree	*root;

	root = xmalloc(sizeof(t_astree));
	root->type = NOT;
	if (!(root->left = pipeline_command()))
		if (!list_terminator())
			return (freeastree(root));
printf("OK\n");
	return (root);
}

t_astree		*pipeline_command(void)
{
	t_astree	*root;

	if (checktype(NOT))
		return (get_pipline_bang());
	root = xmalloc(sizeof(t_astree));
	root->type = PIPECMD;
	if (!(root->left = pipeline()))
		return (freeastree(root));
	return (root);
}

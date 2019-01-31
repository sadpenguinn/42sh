/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:29:56 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:45:16 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                     /
**		COMLETE_COMMAND
**     /               \
** LIST                 // ?(SEPARATOR_OP | )
*/

#include "parser.h"

t_astree	*complete_command(void)
{
	t_astree	*res;
	t_astree	*root;

	if (!(res = list()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	/* XXX - Need norm type */
	root->type = 0;
	/* root->right = separator_op(); */
	return (root);
}

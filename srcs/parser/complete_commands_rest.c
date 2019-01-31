/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_commands_rest.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:12:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 15:45:26 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**             COMPLETE_COMMANDS
**            /                 \
** COMLETE_COMMAND              COMPLETE_COMMANDS_REST
**                              /                \
**               COMLETE_COMMAND                  COMPLETE_COMMANDS_REST
**                                               /                 \
**                                COMLETE_COMMAND                   ...
*/

#include "parser.h"

t_astree	*complete_commands_rest(void)
{
	t_astree	*res;
	t_astree	*root;

	newline_list();
	if (!(res = complete_command()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->left = res;
	/* XXX - Need norm type */
	root->type = 0;
	root->right = complete_commands_rest();
	return (root);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:05:24 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 12:13:41 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SCE - Simple Command Element
** SC - Simple Command
**
**     SC
**    /  \
** SCE    SC
**       /  \
**    SCE    ...
*/

#include "parser.h"

t_astree	*simple_command(void)
{
	t_astree	*root;
	t_astree	*res;
printf("in simple_command\n");
	if (!(res = simple_command_element()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = COMMAND;
	root->left = res;
	root->right = simple_command();
	return (root);
}

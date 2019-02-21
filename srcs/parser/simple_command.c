/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:05:24 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 14:35:52 by bwerewol         ###   ########.fr       */
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
printf("in simple_command\n");
	t_astree	*root;
	t_astree	*res;

	if (!(res = simple_command_element()))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = COMMAND;
	root->left = res;
	root->right = simple_command();
printf("simple root\n");
	return (root);
}

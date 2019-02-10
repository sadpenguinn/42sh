/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:05:24 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/31 16:07:24 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*simple_command(void)
{
	t_astree	*root;
	t_astree	*res;

	res = cmd_prefix();
	if (!(root = cmd_word()))
		root = xmalloc(sizeof(t_astree));
	root->type = COMMAND;
	root->left = res;
	root->right = cmd_suffix();
	return (root);
}

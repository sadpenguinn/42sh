/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_list_rest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:55:50 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 17:07:18 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**        COMPOUND_LIST
**       /             \
** AND_OR               COMPOUND_LIST_REST(type:sep)
**                     /                  \
**               AND_OR                    COMPOUND_LIST_REST(type:sep)
**                                        /
**                                       0
*/

#include "parser.h"

t_astree	*compound_list_rest(void)
{
	t_astree	*root;

	if (!(root = separator_op()))
		return (0);
	if (!(root->left = and_or()))
		return (root);
	root->right = complete_commands_rest();
	return (root);
}

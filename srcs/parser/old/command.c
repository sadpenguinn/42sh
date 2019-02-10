/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:06:37 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/02 13:23:43 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**                 /
**   SIMPLE_COMMAND
**  /              \
*/

/*
**                         /
**                  COMMAND
**                 /       \
** COMPOUND_COMMAND         REDIRECT_LIST
*/

#include "parser.h"

t_astree        *command(void)
{
	unsigned int	tmpcur;
	t_astree		*root;
	t_astree		*res[2];

	tmpcur = g_curtok;
	if ((res[0] = compound_command()))
	{
		if (!(res[1] = redirect_list()))
			return (res[0]);
		root = xmalloc(sizeof(t_astree));
		root->type = COMMAND;
		root->left = res[0];
		root->right = res[1];
		return (root);
	}
	g_curtok = tmpcur;
	if ((root = function_definition()))
		return (root);
	g_curtok = tmpcur;
	if ((root = simple_command()))
		return (root);
	return (0);
}

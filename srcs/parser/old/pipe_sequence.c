/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:42:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/01 18:41:25 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <---IF NO REST--->
**
**        /
** COMMAND
*/

/*
**                          /
**         PIPELINE_SEQUENCE(type:PIPE)
**        /                 \
** COMMAND                   PIPELINE_SEQUENCE_REST(type:PIPE)
**                          /                      \
**                   COMMAND                PIPELINE_SEQUENCE_REST(type:PIPE)
*/

#include "parser.h"

t_astree	*pipeline_sequence(void)
{
	t_astree	*res[2];
	t_astree	*root;

	if (!(res[0] = command()))
		return (0);
	if (!(res[1] = pipeline_sequence_rest()))
		return (res[0]);
	root = xmalloc(sizeof(t_astree));
	root->type = PIPE;
	root->left = res[0];
	root->left = res[1];
	return (root);
}

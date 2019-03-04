/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:42:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:44:02 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr8(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr9()))
		return (0);
	if (!(res[1] = expr8_rest()))
		return (res[0]);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:50:55 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:08:10 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr14(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = operand()))
		return (0);
	if (!(res[1] = expr14_rest()))
		return (res[0]);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

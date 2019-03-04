/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:45:48 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:06:48 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr13(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr14()))
		return (0);
	if (!(res[1] = expr13_rest()))
		return (res[0]);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EX_EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

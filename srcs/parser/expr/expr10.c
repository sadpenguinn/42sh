/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:48:07 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 20:00:48 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr10(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr11()))
		return (0);
	if (!(res[1] = expr10_rest()))
		return (res[0]);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

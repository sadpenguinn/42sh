/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:45:14 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 19:47:42 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*expr9(void)
{
	t_astree	*root;
	t_astree	*res[2];

	if (!(res[0] = expr10()))
		return (0);
	if (!(res[1] = expr9_rest()))
		return (res[0]);
	if (!(root = ft_memalloc(sizeof(t_astree))))
		return (0);
	root->type = EXPR;
	root->left = res[0];
	root->right = res[1];
	return (root);
}

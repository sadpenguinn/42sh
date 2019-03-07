
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:39:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/20 15:19:50 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree		*expr(void)
{
	t_astree	*root;

	root = expr1();
	if (!checktype(TOKEOF))
		return (parseerror(root));
	return (root);
}

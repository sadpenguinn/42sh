/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postincdec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:37:08 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/21 18:01:21 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expr.h"

t_astree	*postincdec(void)
{
	t_astree	*root;

	if (!(root = variable()))
		return (0);
	root->left = postincdec_rest();
	return (root);
}

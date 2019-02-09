/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compound_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:02:16 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/09 19:39:24 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*compound_list(void)
{
	t_astree	*root;

	root = xmalloc(sizeof(t_astree));
	root->content = ft_strdup("CMPD");
	return (root);
}


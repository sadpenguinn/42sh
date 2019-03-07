/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:00:53 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree	*group_command(void)
{
	t_astree	*root;

	if (!checktype(OBRACE))
		return (0);
	if (!(root = compound_list()))
		return (parseerror(0));
	if (!checktype(CBRACE))
		return (parseerror(root));
	return (root);
}

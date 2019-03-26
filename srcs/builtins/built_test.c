/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:13:06 by nkertzma          #+#    #+#             */
/*   Updated: 2019/03/26 17:50:15 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "conditions.h"

/*
** Evaluate a conditional expression expr
** and return a status of 0 (true) or 1 (false)
** test expr
*/

int		built_test(char **av, char **env)
{
	env = NULL;
	if (!av)
		return (SHERR_ERR);
	return (conditions(++av) ? 0 : 1);
}

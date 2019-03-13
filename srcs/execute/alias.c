/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execfor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:10:38 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 22:45:42 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int		set_alias_arg(t_list **args)
{
	int		i;
	char	*arg1;
	char	**alias;

	arg1 = (char *)(*args)->data;
	if (!(alias = alias_get_arr(arg1, g_aliases)))
		return (0);
	free(ft_pop(args));
	i = 0;
	while (alias[i])
		i++;
	while (--i >= 0)
		ft_push(args, alias[i]);
	free(alias);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinvect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:08:32 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clearvect(void **arr)
{
	void	**tmp;

	if (!arr)
		return ;
	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(*tmp);
	free(arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xrealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:39:50 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/09 20:55:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshell.h"

void	*xrealloc(void *p, size_t newsize, size_t oldsize)
{
	void	*temp;

	if (!(temp = realloc(p, newsize)))
	{
		write(2, "cannot allocate memory\n", 23);
		exit(EXIT_FAILURE);
	}
	if (newsize > oldsize)
		ft_memset(temp + oldsize, 0, newsize - oldsize);
	return (temp);
}

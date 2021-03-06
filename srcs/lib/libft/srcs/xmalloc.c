/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:07:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:34 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*xmalloc(size_t bytes)
{
	void	*temp;

	if (!(temp = malloc(bytes)))
	{
		write(2, "cannot allocate memory\n", 23);
		exit(EXIT_FAILURE);
	}
	ft_memset(temp, 0, bytes);
	return (temp);
}

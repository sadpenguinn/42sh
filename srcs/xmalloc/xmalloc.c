/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:07:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/06 18:56:25 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "shell.h"

void	*xmalloc(size_t bytes)
{
	void	*temp;

	if (!(temp = malloc(bytes)))
	{
		write(2, "cannot allocate memory\n", 23);
		exit(EXIT_FAILURE);
	}
	memset(temp, 0, bytes);
	return (temp);
}

void	*xrealloc(void *p, size_t newsize, size_t oldsize)
{
	void	*temp;

	if (!(temp = realloc(p, newsize)))
	{
		write(2, "cannot allocate memory\n", 23);
		exit(EXIT_FAILURE);
	}
	if (newsize > oldsize)
		memset(temp + oldsize, 0, newsize - oldsize);
	return (temp);
}

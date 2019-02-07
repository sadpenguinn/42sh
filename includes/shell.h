/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:39:09 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/07 10:42:11 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
#define SHELL_H

# include <stdlib.h>

void	*xmalloc(size_t bytes);
void	*xrealloc(void *p, size_t newsize, size_t oldsize);

/*
**	<|Token defines|>
**
*/

# define WORD			77
#endif

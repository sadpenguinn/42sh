/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:24 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/10 19:35:12 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
#define LIBSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "libft.h"

void	*xmalloc(size_t bytes);
void	*xrealloc(void *p, size_t newsize, size_t oldsize);
int		check_varname(char *var);
int		match(char *s1, char *s2);
int		glob(char *pattern, char *path, char ***matches, int *cnt);

#endif
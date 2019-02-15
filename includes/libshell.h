/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:24 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:37:10 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "libft.h"
# include "libhash.h"

void	*xmalloc(size_t bytes);
void	*xrealloc(void *p, size_t newsize, size_t oldsize);
int		check_varname(char *var);
int		match(char *s1, char *s2);
int		glob(char *pattern, char *path, char ***matches, int *cnt);
void	die(void);
void 	serror(char *str);
char 	*sstrerr(int e);
char	*check_valid_of_variable(char *str);

char 	*sgetenv(char *key);
int 	ssetenv(char *str);

#endif

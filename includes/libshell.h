/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:24 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 20:18:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "libft.h"
# include "libhash.h"

int		check_varname(char *var);
int		match(char *s1, char *s2);
int		glob(char *pattern, char *path, char ***matches, size_t *cnt);
void	die(void);
void 	sputerr(char *str);
char 	*sstrerr(int e);
char	*check_valid_of_variable(char *str);

char 	*sgetenv(char *key);
int 	ssetenv(char *key, char *value);
int 	sunsetenv(char *key);
int 	keyvaluecmp(char *el1, char *el2);

void 	free_str_arr(char ***arr);
char 	**split_env(char *str);

#endif

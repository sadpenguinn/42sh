/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:34:24 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/26 21:48:25 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include "libft.h"
# include "libhash.h"

int		check_varname(char *var);
int		match(char *s1, char *s2);
int		xglob(char *pattern, char *path, char ***matches, size_t *cnt);
void	die(void);
void	sputerr(char *err);
void	sputcmderr(char *err, char *cmd, char *arg);
char	*sstrerr(int e);
char	*check_valid_of_variable(char *str);

char	*sgetenv(const char *key);
int		ssetenv(const char *key, const char *value);
int		sunsetenv(const char *key);

void	free_str_arr(char ***arr);
void	print_str_arr(char *const *arr);
char	**split_env(char *str);

char	*sgetpath(const char *bin);
char	*get_cmd_path(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:36:41 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/28 21:10:17 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include <dirent.h>
# include "libft.h"

int		match(char *s1, char *s2);
int		glob(char *pattern, char *path, char ***matches, int *cnt);
int		check_var(char *var);

#endif

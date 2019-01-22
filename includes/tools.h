/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:36:41 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/20 16:12:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include <dirent.h>
# include "libft.h"

int		match(char *s1, char *s2);
int		glob(char *pattern, char *path, char ***matches, int *cnt);

#endif

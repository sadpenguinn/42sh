/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clever_autocomplete_checks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:56:34 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 11:04:57 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"


/*
**	If you know some cases with only files - please report me.
**	This case is off, beacause user must can open a file in dir :(
*/
int		check_only_files_case_type(char *str)
{
	if (!ft_strcmp(str, "vim") || !ft_strcmp(str, "nano") ||
		!ft_strcmp(str, "emacs") || !ft_strcmp(str, "cat"))
		return (0);
	return (0);
}

int		check_only_dir_case_type(char *str)
{
	if (!ft_strcmp(str, "cd"))
		return (1);
	return (0);
}

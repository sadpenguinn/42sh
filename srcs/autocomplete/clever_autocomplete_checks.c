/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clever_autocomplete_checks.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:56:34 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 13:11:37 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		check_only_files_case_type(char *str)
{
	if (!ft_strcmp(str, "vim") || !ft_strcmp(str, "nano") ||
		!ft_strcmp(str, "emacs") || !ft_strcmp(str, "cat"))
		return (1);
	return (0);
}

int		check_only_dir_case_type(char *str)
{
	if (!ft_strcmp(str, "cd"))
		return (1);
	return (0);
}

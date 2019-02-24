/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strins_sheets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:32:34 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/24 19:39:00 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_classic_var(char *str)
{
	char	*res;

	res = get_content_of_var(&str[1]);
	free(str);
	if (res)
		return (res);
	return (ft_strdup(""));
}

char	*erase_repetitions_recursion(char *str)
{
	char	*tmp;

	tmp = ft_strchr(&str[1], '$');
	if (!tmp)
		return (str);
	return (ft_strjoin("$", expand(&str[1]), 0));
}

char 	*classic_get_env(char *str)
{
	char *res;

	res = sgetenv(str);
	if (!res)
		return (ft_strdup(""));
	else
		return (ft_strdup(res));
}

char	*get_last_n_symbols(char *str, int n, int freed)
{
	int		i;
	char	*res;

	i = ft_strlen(str) - n;
	res = ft_strdup(&str[i]);
	if (freed)
		free(str);
	return (res);
}
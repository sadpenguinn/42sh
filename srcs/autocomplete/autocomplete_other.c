/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:56:27 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 09:57:03 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	**get_mas_other_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;

	iter = 0;
	len = autocomplite_hash_find_len(g_path, str) +
			get_autocomplite_built_in_mas_len(str) +
			get_autocomplite_functions_mas_len(str) +
			get_autocomplite_files_dir_len(str);
	if (!len)
		return (NULL);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = autocomplite_hash_find(g_path, str, res, &iter);
	res = get_autocomplite_built_in_mas(str, res, &iter);
	res = get_autocomplite_files_dir_mas(str, res, &iter);
	res = get_autocomplite_functions_mas(str, res, &iter);
	return (res);
}

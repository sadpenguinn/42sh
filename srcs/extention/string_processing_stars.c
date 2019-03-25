/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_processing_stars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 00:07:50 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 00:08:13 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char			*get_string_from_tab_after_xglob(char **str)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_strlen(str[i]) + 1;
		i++;
	}
	res = xmalloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i])
	{
		ft_strcat(res, str[i]);
		if (str[i + 1])
			ft_strcat(res, " ");
		free(str[i]);
		i++;
	}
	free(str);
	return (res);
}

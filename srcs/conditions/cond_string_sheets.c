/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_string_sheets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:43:00 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/21 10:28:18 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		ft_exit_with_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

int		ft_tab_len(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

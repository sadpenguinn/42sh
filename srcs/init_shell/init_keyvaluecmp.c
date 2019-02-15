/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keyvaluecmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:09:50 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:09:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int 	keyvaluecmp(void *el1, size_t cs1, void *el2, size_t cs2)
{
	char	*str1;
	char 	*str2;

	str1 = (char *)el1;
	str2 = (char *)el2;
	while (*str1 && *str2 && *str1 != '=')
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if (!*str1 || (*str1 == '=' && !*(str1 + 1)))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_str_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:23:42 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/28 15:24:57 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

/*
** Returns size of two-dimensional array of strings
*/

size_t		size_str_arr(char *const *arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

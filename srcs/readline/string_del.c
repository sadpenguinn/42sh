/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:26:06 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:26:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	string_del(t_string **str)
{
	if (str == NULL)
		return ;
	string_free(*str);
	*str = NULL;
}

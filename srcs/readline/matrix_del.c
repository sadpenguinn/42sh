/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:13:03 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:13:04 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdlib.h>

void	matrix_del(t_matrix **matrix)
{
	if (matrix == NULL)
		return ;
	matrix_free(*matrix);
	*matrix = NULL;
}

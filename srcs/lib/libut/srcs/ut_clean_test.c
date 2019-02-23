/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_clean_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:59:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libut.h"

/*
** Cleans the tests array and all internal variables
*/

void	ut_clean_test(t_utest *tests)
{
	free(tests);
}

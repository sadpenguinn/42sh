/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_clean_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:59:55 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/24 16:15:16 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"

void	ut_clean_test(t_utest *ut)
{
	t_utest	*tmp;

	while (ut)
	{
		tmp = ut->next;
		free(ut->input);
		free(ut->expect);
		free(ut);
		ut = tmp;
	}
}

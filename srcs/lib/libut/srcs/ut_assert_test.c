/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_assert_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:07:12 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/09 17:19:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libut.h"

void	ut_assert_test(char *result, char *expectation)
{
	ft_putstr("Result: ");
	ft_putendl(result);
	ft_putstr("Excpect: ");
	ft_putendl(expectation);
}

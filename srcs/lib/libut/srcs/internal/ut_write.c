/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony </var/mail/tony>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:35:49 by tony              #+#    #+#             */
/*   Updated: 2019/02/21 10:55:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libut.h"
#include "../../includes/ut_utils.h"

void	write_result(size_t count_passed, size_t total)
{
	if (!count_passed || !total || total < count_passed)
		ft_putstr(UT_COLOR_FAIL);
	else if ((int)((float)count_passed / (float)total * (float)100) < 75)
		ft_putstr(UT_COLOR_FAIL);
	else
		ft_putstr(UT_COLOR_OK);
	ft_putchar('\n');
	ft_putnbr(count_passed);
	ft_putstr(" tests passed / ");
	ft_putnbr(total);
	ft_putendl(" total");
	ft_putstr(UT_COLOR_DEFAULT);
}

void	write_prompt(int id)
{
	ft_putstr("*=== Test ");
	ft_putnbr(id);
	ft_putendl(" ===*");
}

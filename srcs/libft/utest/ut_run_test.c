/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_run_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:41 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 15:43:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utest.h"

void	write_prompt(int id)
{
	/* if (id > 0) */
	/* 	ft_putchar('\n'); */
	ft_putstr("*=== Test ");
	ft_putnbr(id);
	ft_putendl(" ===*");
}

void	assert(int ret, int *count_passed)
{
	if (ret == UT_TEST_PASSED)
	{
		*count_passed += 1;
		ft_putendl("\x1b[32mOK\x1b[0m");
	}
	else if (ret == UT_TEST_FAILED)
		ft_putendl("\x1b[31mFAIL\x1b[0m");
	else
		ft_putendl("Internal Error");
}

void	write_result(int count_passed, int total)
{
	if (!count_passed || !total || total < count_passed)
		ft_putstr("\x1b[31m");
	else if ((int)((float)count_passed / (float)total * (float)100) < 75)
		ft_putstr("\x1b[31m");
	else
		ft_putstr("\x1b[32m");
	ft_putchar('\n');
	ft_putnbr(count_passed);
	ft_putstr(" tests passed / ");
	ft_putnbr(total);
	ft_putendl(" total");
	ft_putstr("\x1b[0m");
}

int		ut_run_test(t_utest *ut)
{
	int		ret;
	int		count_passed;
	int		total;

	if (!ut)
		return (UT_INVALID_INPUT);
	total = 0;
	count_passed = 0;
	while (ut)
	{
		write_prompt(ut->id);
		ret = (ut->test)(ut->input, ut->expect);
		assert(ret, &count_passed);
		total++;
		ut = ut->next;
	}
	write_result(count_passed, total);
	return (UT_OK);
}

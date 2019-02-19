/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_run_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:05:41 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/18 11:46:45 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libut.h"
#include "../includes/ut_utils.h"

static size_t	g_count_passed = 0;
static size_t	g_total = 0;
size_t			g_utcur = 0;

void			ut_check_test(t_utest *cur)
{
	int		ret;

	write_prompt(cur->id);
	ret  = (cur->sample)(cur->input, cur->expect);
	if (ret == UT_TEST_PASSED)
	{
		g_count_passed++;
		ft_putendl(UT_COLOR_OK"OK"UT_COLOR_DEFAULT);
	}
	else if (ret == UT_TEST_FAILED)
		ft_putendl(UT_COLOR_FAIL"FAIL"UT_COLOR_DEFAULT);
	else
		ft_putendl("Internal Error");
	g_total++;
}

void			ut_arr_foreach(t_utest *tests, void (*check)(t_utest *cur))
{
	t_utest	*cur;
	size_t	indent;
	size_t	i;
	size_t	len;

	i = 0;
	len = g_utinfo.filled;
	while (i < len)
	{
		g_utcur = i;
		indent = sizeof(t_utest) * i;
		cur = tests + indent;
		(check)(cur);
		i++;
	}
}

/*
** Function runs test in tests array
*/

int				ut_run_test(t_utest *tests)
{
	if (!tests)
		return (ut_ret(UT_INVALID_INPUT));
	ut_arr_foreach(tests, ut_check_test);
	write_result(g_count_passed, g_total);
	return (ut_ret(UT_OK));
}

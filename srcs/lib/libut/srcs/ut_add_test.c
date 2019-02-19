/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_add_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:43:46 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/18 11:46:45 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libut.h"
#include "../includes/ut_utils.h"

int		ut_arr_resize(t_utest **tests)
{
	size_t	resize;
	t_utest	*new;

	if (UT_ARR_RESIZE <= 0)
		return (ut_ret(UT_INVALID_INPUT));
	resize = UT_ARR_RESIZE / 100 * g_utinfo.size;
	resize = resize + g_utinfo.size;
	if (!(new = (t_utest *)malloc(sizeof(t_utest) * resize)))
		return (ut_ret(UT_MALLOC_CRUSHED));
	ft_memmove(new, *tests, sizeof(t_utest) * g_utinfo.size);
	free(*tests);
	*tests = new;
	g_utinfo.size = resize;
	return (ut_ret(UT_OK));
}

int		ut_insert_test(t_utest **tests, t_utest new)
{
	t_utest		*ptr;
	size_t		indent;

	if (g_utinfo.filled >= g_utinfo.size)
		return (ut_arr_resize(tests));
	indent = sizeof(t_utest) * g_utinfo.filled;
	ptr = *tests + indent;
	ft_memmove(ptr, &new, sizeof(t_utest));
	g_utinfo.filled++;
	return (ut_ret(UT_OK));
}

/*
** Function adds new tests to tests array
*/

int		ut_add_test(t_utest **tests,
					int (*sample)(char *input, char *expect), t_uinput *input)
{
	t_utest		new;

	if (!tests || !*tests || !input || !input->input || !input->expect || !sample)
		return (ut_ret(UT_INVALID_INPUT));
	new.sample = sample;
	new.input = input->input;
	new.expect = input->expect;
	new.flags = input->flags;
	new.id = g_utinfo.filled;
	return (ut_insert_test(tests, new));
}

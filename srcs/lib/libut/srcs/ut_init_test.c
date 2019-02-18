/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_init_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony </var/mail/tony>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:24:59 by tony              #+#    #+#             */
/*   Updated: 2019/02/17 17:23:23 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libut.h"

t_uinfo		g_utinfo;
int			g_uterrno = UT_OK;

t_utest		*ut_init_arr(size_t init_arr_size, int flag)
{
	t_utest		*tests;

	if (!(tests = (t_utest *)malloc(sizeof(t_utest) * init_arr_size)))
	{
		g_uterrno = UT_MALLOC_CRUSHED;
		return (NULL);
	}
	ft_bzero(tests, sizeof(t_utest) * init_arr_size);
	g_utinfo.size = init_arr_size;
	g_utinfo.filled = 0;
	g_utinfo.wtf = flag;
	return (tests);
}

/*
** Initialize function for utest. This allocates memory
** for tests arr with init_arr_size variable or
** UT_INIT_ARR_SIZE define. Optional second parameter
** makes ut writes results to files
*/

t_utest		*ut_init_test(size_t init_arr_size, ...)
{
	va_list ap;
	int		flag;

	va_start(ap, init_arr_size);
	flag = va_arg(ap, int);
	if (flag != UT_WRITE_TO_FILE)
		flag = 0;
	va_end(ap);
	ft_bzero(&g_utinfo, sizeof(g_utinfo));
	if (!init_arr_size)
		init_arr_size = UT_INIT_ARR_SIZE;
	if (init_arr_size <= 0)
	{
		g_uterrno = UT_INVALID_INPUT;
		return (NULL);
	}
	return (ut_init_arr(init_arr_size, flag));
}

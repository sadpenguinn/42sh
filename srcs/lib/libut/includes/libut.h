/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libut.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:56:48 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/17 17:29:19 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUT_H
# define LIBUT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

/*
** UTest functions return one if this values.
** If ret is a pointer, NULL will be returned in error case
** and g_uterrno will be marked with an error code
*/
# define UT_OK 0
# define UT_INVALID_INPUT 1
# define UT_MALLOC_CRUSHED 2
# define UT_CNNT_CRT_DIR 3

/*
** Sample must return  one of this
*/
# define UT_TEST_PASSED 3
# define UT_TEST_FAILED 4

/*
** Defines for mark input with bitwise 'or'.
** UT_FILE_IN | UT_STRING_EXP will be interpreted like this:
** input for test case passed as a name of file, but
** expected value passed as a string
*/
#define UT_FILE_IN 0b00000001
#define UT_STRING_IN 0b00000010
#define UT_FILE_EXP 0b00010000
#define UT_STRING_EXP 0b00100000

/*
** FLag for pass to ut_init_test as second parameter.
** If flag is passed, ut will save the result in dir,
** named as UT_TMP_DIR_NAME
*/
# define UT_WRITE_TO_FILE 1
# define UT_TMP_DIR_NAME "tmp"

/*
** Internal parameters with initial array size and
** realloc size in percents
*/
# define UT_INIT_ARR_SIZE 20
# define UT_ARR_RESIZE 150

/*
** Internal defines for formatting output
*/
# define UT_COLOR_OK "\x1b[32m"
# define UT_COLOR_FAIL "\x1b[31m"
# define UT_COLOR_DEFAULT "\x1b[0m"

/*
** Struct witch stores info for one test
*/
typedef struct	s_utest
{
	size_t		id;
	int			(*sample)(char *input, char *expect);
	char		*input;
	char		*expect;
	int			flags;
}				t_utest;

/*
** Internal struct for store array size etc.
*/
typedef struct	s_uinfo
{
	size_t		size;
	size_t		filled;
	int			wtf;
}				t_uinfo;

/*
** Struct for pass parameters to ut_add_test.
** Example:
**
** t_uinput input;
** input.input = "Hello";
** input.expect = "hello";
** input.flags = UT_STRING_IN | UT_STRING_EXP
** ut_add_test(&tests, sample, input);
*/
typedef struct	s_uinput
{
	char		*input;
	char		*expect;
	int			flags;
}				t_uinput;

/*
** g_uterrno stores the error define like a standart errno
*/
extern int		g_uterrno;

/*
** Internal global varialbes
*/
extern t_uinfo	g_utinfo;
extern size_t	g_utcur;

/*
** Initialize function for utest. This allocates memory
** for tests arr with init_arr_size variable or
** UT_INIT_ARR_SIZE define. Optional second parameter
** makes ut writes results to files
*/
t_utest			*ut_init_test(size_t init_arr_size, ...);

/*
** Function adds new tests to tests array
*/
int				ut_add_test(t_utest **tests,
				int (*sample)(char *input, char *expect), t_uinput *input);

/*
** Function runs test in tests array
*/
int				ut_run_test(t_utest *tests);

/*
** Cleans the tests array and all internal variables
*/
void			ut_clean_test(t_utest *tests);

/*
** Function to be called in the user 'sample' function
*/
int				ut_assert(char *result, char *expect);

#endif

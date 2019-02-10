/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libut.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:56:48 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/24 16:17:01 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUT_H
# define LIBUT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define UT_OK 0
# define UT_INVALID_INPUT 1
# define UT_MALLOC_CRUSHED 2
# define UT_TEST_PASSED 3
# define UT_TEST_FAILED 4

typedef struct	s_utest
{
	int				id;
	int				(*test)(void *input, void *expect);
	void			*input;
	size_t			input_size;
	void			*expect;
	size_t			expect_size;
	struct s_utest	*next;
}				t_utest;

typedef struct	s_uinput
{
	void		*input;
	size_t		input_size;
	void		*expect;
	size_t		expect_size;
}				t_uinput;

int				ut_add_test(t_utest **ut, int (*test)(void *input, void *expect),
														t_uinput *input);
int				ut_run_test(t_utest *ut);
void			ut_assert_test(char *result, char *expectation);
void			ut_clean_test(t_utest *ut);

#endif

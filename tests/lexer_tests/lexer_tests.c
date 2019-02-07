/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:39:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/06 19:46:25 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		lexer_tests_sample(void *input, void *expect)
{
	t_lexer	*lex;
	t_lexem	*lexem;
	char	*ret;
	char	*res;
	int		len;
	int		i;

	i = 0;
	res = ft_strnew(0);
	lex = lexer((char *)input);
	len = vector_get_len(lex->lexems);
	while (i < len)
	{
		lexem = (t_lexem *)vector_get_elem(lex->lexems, i);
		ret = lexem->word;
		res = ft_strjoin(res, DELIM, 0);
		res = ft_strjoin(res, ret, 0);
		i++;
	}
	ut_assert_test(res, (char *)expect);
	if (!ft_strcpy(res, (char *)expect))
		return (UT_TEST_FAILED);
	else
		return (UT_TEST_PASSED);
}

void	lexer_tests(void)
{
	t_utest		*tests;
	t_uinput	input;
	void		*vector;

	ft_putchar('\n');
	ft_putendl("###########################################");
	ft_putendl("########     TRIM QUOTES TESTS     ########");
	ft_putendl("###########################################");
	ft_putchar('\n');

	tests = NULL;

	input.input = "abc>>=abc";
	input.input_size = 10;
	input.expect = DELIM"abc"DELIM">>="DELIM"abc";
	input.expect_size = 10 + (DELIM_SIZE * 3);
	ut_add_test(&tests, lexer_tests_sample, &input);

	ut_run_test(tests);
}

int		main(void)
{
	/* trim_quotes_tests(); */
	lexer_tests();
	return (0);
}

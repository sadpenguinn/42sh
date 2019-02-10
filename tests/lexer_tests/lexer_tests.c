/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:39:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/10 19:37:59 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

char	*lexer_tests_get_res(t_lexer *lex)
{
	t_lexem	*lexem;
	char	*ret;
	char	*res;
	int		len;
	int		i;

	i = 0;
	res = ft_strnew(0);
	len = (int)vector_get_len(lex->lexems);
	while (i < len)
	{
		lexem = (t_lexem *)vector_get_elem(lex->lexems, (size_t)i);
		ret = lexem->word;
		res = ft_strjoin(res, TESTS_DELIM, 1);
		res = ft_strjoin(res, ret, 1);
		i++;
	}
	return (res);
}

int		lexer_tests_sample(void *input, void *expect)
{
	t_lexer	*lex;
	char 	*res;

	lex = lexer((char *)input, ft_strlen((char *)input));
	res = lexer_tests_get_res(lex);
	ut_assert_test(res, (char *)expect);
	free(lex->lexems);
	free(lex->symbol_table);
	free(lex);
	if (!ft_strcpy(res, (char *)expect))
	{
		free(res);
		return (UT_TEST_FAILED);
	}
	else
	{
		free(res);
		return (UT_TEST_PASSED);
	}
}

void	lexer_tests(void)
{
	t_utest		*tests;
	t_uinput	input;

	ft_putchar('\n');
	ft_putendl("###########################################");
	ft_putendl("########     TRIM QUOTES TESTS     ########");
	ft_putendl("###########################################");
	ft_putchar('\n');
	tests = NULL;

	/* TEST 0 */
	input.input = "abc>>=abc";
	input.input_size = 10;
	input.expect = TESTS_DELIM"abc"TESTS_DELIM">>="TESTS_DELIM"abc";
	input.expect_size = 10 + (TESTS_DELIM_SIZE * 3);
	ut_add_test(&tests, lexer_tests_sample, &input);

	/* TEST 1 */
	input.input = "abc>>=abc";
	input.input_size = 10;
	input.expect = TESTS_DELIM"abc"TESTS_DELIM">>="TESTS_DELIM"abc";
	input.expect_size = 10 + (TESTS_DELIM_SIZE * 3);
	ut_add_test(&tests, lexer_tests_sample, &input);




	ut_run_test(tests);
	ut_clean_test(tests);
}

int		main(void)
{
	lexer_tests();
	return (0);
}

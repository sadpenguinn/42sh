/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:44:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 17:15:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "vector.h"
#include "utest.h"

int		trim_quotes_tests_sample(void *input, void *expect)
{
	char	*trim;

	if (!(trim = trim_quotes((char *)input)))
		return (UT_MALLOC_CRUSHED);
	ut_assert_test(trim, (char *)expect);
	if (!ft_strcmp(trim, (char *)expect))
	{
		free(trim);
		return (UT_TEST_PASSED);
	}
	else
	{
		free(trim);
		return (UT_TEST_FAILED);
	}
}

void	trim_quotes_tests(void)
{
	t_utest		*tests;
	t_uinput	input;

	ft_putchar('\n');
	ft_putendl("###########################################");
	ft_putendl("########     TRIM QUOTES TESTS     ########");
	ft_putendl("###########################################");
	ft_putchar('\n');

	tests = NULL;
	input.input = "hello \"world\"";
	input.input_size = 14;
	input.expect = "hello \"world\"";
	input.expect_size = 14;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"world and world\"";
	input.input_size = 23;
	input.expect = "hello \"world and world\"";
	input.expect_size = 23;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"world\" and \"world\"";
	input.input_size = 25;
	input.expect = "hello \"world\" and \"world\"";
	input.expect_size = 25;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"world\"and \"world\"";
	input.input_size = 25;
	input.expect = "hello \"worldand\" \"world\"";
	input.expect_size = 25;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wor ld\" and \"world\"";
	input.input_size = 25;
	input.expect = "hello \"wor ld\" and \"world\"";
	input.expect_size = 25;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wor ld\"and \"world\"";
	input.input_size = 25;
	input.expect = "hello \"wor ldand\" \"world\"";
	input.expect_size = 25;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wor\'ld\"";
	input.input_size = 14;
	input.expect = "hello \"wor\'ld\"";
	input.expect_size = 14;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wo\'r\'ld\"";
	input.input_size = 15;
	input.expect = "hello \"wo\'r\'ld\"";
	input.expect_size = 15;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wo\'rld\" \"wor\'ld\"";
	input.input_size = 23;
	input.expect = "hello \"wo\'rld\" \"wor\'ld\"";
	input.expect_size = 23;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello\' \"world\'";
	input.input_size = 19;
	input.expect = "cat \"hello\' world\"\'";
	input.expect_size = 19;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello\' \"world\'\'";
	input.input_size = 20;
	input.expect = "cat \"hello\' world\"\'\'";
	input.expect_size = 20;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \'hello\" \'world\"";
	input.input_size = 19;
	input.expect = "cat \'hello\" world\'\"";
	input.expect_size = 19;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"world\"\tand \"world\"";
	input.input_size = 25;
	input.expect = "hello \"world\"\tand \"world\"";
	input.expect_size = 25;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"world\"\nand \"world\"";
	input.input_size = 25;
	input.expect = "hello \"world\"\nand \"world\"";
	input.expect_size = 25;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wor\tld\"";
	input.input_size = 14;
	input.expect = "hello \"wor\tld\"";
	input.expect_size = 14;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"wor\nld\"";
	input.input_size = 14;
	input.expect = "hello \"wor\nld\"";
	input.expect_size = 14;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\" world\"";
	input.input_size = 20;
	input.expect = "cat \"hello  world\"";
	input.expect_size = 18;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\'\'\" world\"";
	input.input_size = 22;
	input.expect = "cat \"hello  world\"";
	input.expect_size = 18;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\" \"\" sefwef\"";
	input.input_size = 24;
	input.expect = "cat \"hello   sefwef\"";
	input.expect_size = 20;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\"\"\" sefwef\"";
	input.input_size = 23;
	input.expect = "cat \"hello  sefwef\"";
	input.expect_size = 19;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\' \'\" world\"";
	input.input_size = 23;
	input.expect = "cat \"hello   sefwef\"";
	input.expect_size = 20;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello\\\"\"";
	input.input_size = 13;
	input.expect = "cat \"hello\\\"\"";
	input.expect_size = 13;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"\\\"hello\"";
	input.input_size = 13;
	input.expect = "cat \"\\\"hello\"";
	input.expect_size = 13;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"he\\\'llo\"";
	input.input_size = 13;
	input.expect = "cat \"he\\\'llo\"";
	input.expect_size = 13;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "hello \"world\" and\"world\"";
	input.input_size = 24;
	input.expect = "hello \"world\" \"andworld\"";
	input.expect_size = 24;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\"\"\"\"\" fuck\"";
	input.input_size = 23;
	input.expect = "cat \"hello  fuck\"";
	input.expect_size = 177;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\"\" \"\"\" fuck\"";
	input.input_size = 24;
	input.expect = "cat \"hello \" \" fuck\"";
	input.expect_size = 20;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\"\"\"\"\"\"\" fuck\"";
	input.input_size = 25;
	input.expect = "cat \"hello  fuck\"";
	input.expect_size = 17;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"hello \"\"\"\" \"\"\"\" fuck\"";
	input.input_size = 26;
	input.expect = "cat \"hello   fuck\"";
	input.expect_size = 18;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \'hello\';";
	input.input_size = 11;
	input.expect = "cat \'hello\';";
	input.expect_size = 11;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"abc\"abc";
	input.input_size = 12;
	input.expect = "cat \"abcabc\"";
	input.expect_size = 12;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);

	input.input = "cat \"abc\"cda\"efg\"";
	input.input_size = 17;
	input.expect = "cat \"abccdaefg\"";
	input.expect_size = 15;
	ut_add_test(&tests, trim_quotes_tests_sample, &input);
	ut_run_test(tests);
	ut_clean_test(tests);
}

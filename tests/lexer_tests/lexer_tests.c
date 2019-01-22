/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 12:44:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 19:46:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "vector.h"

#define OK "\033[02;32mOK\033[00m"
#define FAIL "\033[02;31mFAIL\033[00m"

static void	print_lexems(void *lexem)
{
	t_lexem		*lex;

	lex = (t_lexem *)lexem;
	ft_putstr(lex->word);
	if (lex->type > 0)
		ft_putstr(" (terminal)");
	ft_putchar('\n');
}

static int	trim_quotes_tests(void)
{
	char	str1[] = "hello \"world\"";
	char	str2[] = "hello \"world and world\"";
	char	str3[] = "hello \"world\" and \"world\"";
	char	str4[] = "hello \"world\"and \"world\"";
	char	str5[] = "hello \"wor ld\" and \"world\"";
	char	str6[] = "hello \"wor ld\"and \"world\"";
	char	str7[] = "hello \"wor\'ld\"";
	char	str8[] = "hello \"wo\'r\'ld\"";
	char	str9[] = "hello \"wo\'rld\" \"wor\'ld\"";
	char	str10[] = "cat \"hello\' \"world\'";
	char	str11[] = "cat \"hello\' \"world\'\'";
	char	str12[] = "cat \'hello\" \'world\"";
	char	str13[] = "hello \"world\"\tand \"world\"";
	char	str14[] = "hello \"world\"\nand \"world\"";
	char	str15[] = "hello \"wor\tld\"";
	char	str16[] = "hello \"wor\nld\"";
	char	str17[] = "cat \"hello \"\" world\"";
	char	str18[] = "cat \"hello \"\'\'\" world\"";
	char	str19[] = "cat \"hello \"\" \"\" sefwef\"";
	char	str20[] = "cat \"hello \"\"\"\" sefwef\"";
	char	str21[] = "cat \"hello \"\' \'\" world\"";
	char	str22[] = "cat \"hello\\\"\"";
	char	str23[] = "cat \"\\\"hello\"";
	char	str24[] = "cat \"he\\\'llo\"";
	char	str25[] = "hello \"world\" and\"world\"";
	char	str26[] = "cat \"hello \"\"\"\"\"\" fuck\"";
	char	str27[] = "cat \"hello \"\"\" \"\"\" fuck\"";
	char	str28[] = "cat \"hello \"\"\"\"\"\"\"\" fuck\"";
	char	str29[] = "cat \"hello \"\"\"\" \"\"\"\" fuck\"";
	char	str30[] = "cat \'hello\';";
	char	str31[] = "cat \"abc\"abc";
	char	str32[] = "cat \"abc\"cda\"efg\"";
	char	*proc;

	ft_putchar('\n');
	ft_putendl("###########################################");
	ft_putendl("########     TRIM QUOTES TESTS     ########");
	ft_putendl("###########################################");
	ft_putchar('\n');

	ft_putstr("Test 1  ");
	if (!(proc = trim_quotes(str1)))
		return (1);
	ft_strcmp(proc, "hello \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str1);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 2  ");
	if (!(proc = trim_quotes(str2)))
		return (1);
	ft_strcmp(proc, "hello \"world and world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str2);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 3  ");
	if (!(proc = trim_quotes(str3)))
		return (1);
	ft_strcmp(proc, "hello \"world\" and \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str3);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 4  ");
	if (!(proc = trim_quotes(str4)))
		return (1);
	ft_strcmp(proc, "hello \"worldand\" \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str4);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 5  ");
	if (!(proc = trim_quotes(str5)))
		return (1);
	ft_strcmp(proc, "hello \"wor ld\" and \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str5);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 6  ");
	if (!(proc = trim_quotes(str6)))
		return (1);
	ft_strcmp(proc, "hello \"wor ldand\" \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str6);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 7  ");
	if (!(proc = trim_quotes(str7)))
		return (1);
	ft_strcmp(proc, "hello \"wor\'ld\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str7);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 8  ");
	if (!(proc = trim_quotes(str8)))
		return (1);
	ft_strcmp(proc, "hello \"wo\'r\'ld\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str8);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 9  ");
	if (!(proc = trim_quotes(str9)))
		return (1);
	ft_strcmp(proc, "hello \"wo\'rld\" \"wor\'ld\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str9);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 10  ");
	if (!(proc = trim_quotes(str10)))
		return (1);
	ft_strcmp(proc, "cat \"hello\' world\"\'") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str10);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 11  ");
	if (!(proc = trim_quotes(str11)))
		return (1);
	ft_strcmp(proc, "cat \"hello\' world\"\'\'") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str11);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 12  ");
	if (!(proc = trim_quotes(str12)))
		return (1);
	ft_strcmp(proc, "cat \'hello\" world\'\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str12);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 13  ");
	if (!(proc = trim_quotes(str13)))
		return (1);
	ft_strcmp(proc, "hello \"world\"\tand \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str13);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 14  ");
	if (!(proc = trim_quotes(str14)))
		return (1);
	ft_strcmp(proc, "hello \"world\"\nand \"world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str14);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 15  ");
	if (!(proc = trim_quotes(str15)))
		return (1);
	ft_strcmp(proc, "hello \"wor\tld\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str15);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 16  ");
	if (!(proc = trim_quotes(str16)))
		return (1);
	ft_strcmp(proc, "hello \"wor\nld\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str16);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 17  ");
	if (!(proc = trim_quotes(str17)))
		return (1);
	ft_strcmp(proc, "cat \"hello  world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str17);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 18  ");
	if (!(proc = trim_quotes(str18)))
		return (1);
	ft_strcmp(proc, "cat \"hello  world\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str18);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 19  ");
	if (!(proc = trim_quotes(str19)))
		return (1);
	ft_strcmp(proc, "cat \"hello   sefwef\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str19);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 20  ");
	if (!(proc = trim_quotes(str20)))
		return (1);
	ft_strcmp(proc, "cat \"hello  sefwef\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str20);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 21  ");
	if (!(proc = trim_quotes(str21)))
		return (1);
	ft_strcmp(proc, "cat \"hello   sefwef\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str21);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 22  ");
	if (!(proc = trim_quotes(str22)))
		return (1);
	ft_strcmp(proc, "cat \"hello\\\"\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str22);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 23  ");
	if (!(proc = trim_quotes(str23)))
		return (1);
	ft_strcmp(proc, "cat \"\\\"hello\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str23);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 24  ");
	if (!(proc = trim_quotes(str24)))
		return (1);
	ft_strcmp(proc, "cat \"he\\\'llo\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str24);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 25  ");
	if (!(proc = trim_quotes(str25)))
		return (1);
	ft_strcmp(proc, "hello \"world\" \"andworld\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str25);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 26  ");
	if (!(proc = trim_quotes(str26)))
		return (1);
	ft_strcmp(proc, "cat \"hello  fuck\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str26);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 27  ");
	if (!(proc = trim_quotes(str27)))
		return (1);
	ft_strcmp(proc, "cat \"hello \" \" fuck\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str27);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 28  ");
	if (!(proc = trim_quotes(str28)))
		return (1);
	ft_strcmp(proc, "cat \"hello  fuck\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str28);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 29  ");
	if (!(proc = trim_quotes(str29)))
		return (1);
	ft_strcmp(proc, "cat \"hello   fuck\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str29);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 30  ");
	if (!(proc = trim_quotes(str30)))
		return (1);
	ft_strcmp(proc, "cat \'hello\';") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str30);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 31  ");
	if (!(proc = trim_quotes(str31)))
		return (1);
	ft_strcmp(proc, "cat \"abcabc\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str31);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);

	ft_putstr("Test 32  ");
	if (!(proc = trim_quotes(str32)))
		return (1);
	ft_strcmp(proc, "cat \"abccdaefg\"") == 0 ? ft_putendl(OK) : ft_putendl(FAIL);
	ft_putstr("Input: ");
	ft_putendl(str32);
	ft_putstr("Output: ");
	ft_putendl(proc);
	ft_strdel(&proc);
	return (0);
}

static void	lexer_tests(void)
{
	char	str0[] = "cat hello; if [ 5-6 ] then echo 'hello'; fi";
	char	str1[] = "function fuck () { echo 'hello' }";
	char	str2[] = "echo 'Hello, World!'";
	char	str3[] = "cat \"The end of \"the fucking world\"\"";
	char	str4[] = "cat fuckfor";
	char	str5[] = "echo fuck>/etc/world";
	char	str6[] = "cat hello\\ \\ \\ \\ fuck and fuck";
	char	str7[] = "cat hello\\ \\ \\ \\ \tfuck and fuck";
	char	str8[] = "cat \"abc\"abc";
	char	str9[] = "cat \"abc\"cbd\"efg\"";
	void	*lexems;
	t_lexer	*lex;

	ft_putchar('\n');
	ft_putendl("###########################################");
	ft_putendl("########        LEXER TESTS        ########");
	ft_putendl("###########################################");
	ft_putchar('\n');

	ft_putendl("==== TEST 0 ====");
	ft_putstr("Input string: ");
	ft_putendl(str0);
	lex = lexer(str0);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 1 ====");
	ft_putstr("Input string: ");
	ft_putendl(str1);
	lex = lexer(str1);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 2 ====");
	ft_putstr("Input string: ");
	ft_putendl(str2);
	lex = lexer(str2);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 3 ====");
	ft_putstr("Input string: ");
	ft_putendl(str3);
	lex = lexer(str3);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 4 ====");
	ft_putstr("Input string: ");
	ft_putendl(str4);
	lex = lexer(str4);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 5 ====");
	ft_putstr("Input string: ");
	ft_putendl(str5);
	lex = lexer(str5);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 6 ====");
	ft_putstr("Input string: ");
	ft_putendl(str6);
	lex = lexer(str6);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 7 ====");
	ft_putstr("Input string: ");
	ft_putendl(str7);
	lex = lexer(str7);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 8 ====");
	ft_putstr("Input string: ");
	ft_putendl(str8);
	lex = lexer(str8);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);

	ft_putendl("==== TEST 9 ====");
	ft_putstr("Input string: ");
	ft_putendl(str9);
	lex = lexer(str9);
	lexems = lex->lexems;
	vector_foreach(lexems, print_lexems);
	ft_putchar('\n');
	free(lex);
}

int			main(void)
{
	trim_quotes_tests();
	lexer_tests();
	return (0);
}

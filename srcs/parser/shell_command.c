/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:04:30 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 12:33:34 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CMPLST - CoMPound LiST
**
**        WHILE
**       /     \
** CMPLST       CMPLST
**
**        UNTIL
**       /     \
** CMPLST       CMPLST
*/

/*
**	Returns command
*/

#include "parser.h"

static t_astree	*while_command()
{
	t_astree	*root;

	if (!checktype(WHILE))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = WHILE;
	if (!(root->left = compound_list()))
		return (freeastree(root), parseerror());
	if (!checktype(DO))
		return (freeastree(root), parseerror());
	if (!(root->right = compound_list()))
		return (freeastree(root), parseerror());
	if (!checktype(DONE))
		return (freeastree(root), parseerror());
	return  (root);
}

static t_astree	*until_command()
{
	t_astree	*root;

	if (!checktype(UNTIL))
		return (0);
	root = xmalloc(sizeof(t_astree));
	root->type = UNTIL;
	if (!(root->left = compound_list()))
		return (freeastree(root), parseerror());
	if (!checktype(DO))
		return (freeastree(root), parseerror());
	if (!(root->right = compound_list()))
		return (freeastree(root), parseerror());
	if (!checktype(DONE))
		return (freeastree(root), parseerror());
	return  (root);
}

static t_astree	*other_commands()
{
	t_type		type;
	t_astree	*res;

	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == FOR && (res = arith_for_command()))
		return (res);
	else if (type == FOR && (res = for_command()))
		return (res);
	else
		return (arith_command());
}

t_astree		*shell_command(void)
{
printf("in shell_command\n");
	t_type		type;

	if (g_curtok >= ((size_t *)g_tokens)[2])
		return (0);
	type = ((t_lexem *)vector_get_elem(g_tokens, g_curtok))->type;
	if (type == CASE)
		return (case_command());
	if (type == WHILE)
		return (while_command());
	if (type == UNTIL)
		return (until_command());
	if (type == SELECT)
		return (select_command());
	if (type == IF)
		return (if_command());
	if (type == OBRACKET)
		return (subshell());
	if (type == OBRACE)
		return (group_command());
	if (type == COND)
		return (cond_command());
	return (other_commands());
}

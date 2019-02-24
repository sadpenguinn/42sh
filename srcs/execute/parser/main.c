/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:23:54 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 17:23:54 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/*
**            REST
**           /    \
**        CMD      PIPE
**       /        /
**     ls      CMD
**            /   \
**         cat     CMD
**                /
**              -e
**
*/

int main(void)
{
	t_astree	tree[100];
	int			fd[2];

	fd[0] = 0;
	fd[1] = 1;
	bzero(tree, sizeof(t_astree) * 100);

	tree[0].type = LIST2;
	tree[0].right = &tree[1];
	tree[0].left = &tree[10];

	tree[1].type = OR_IF;
	tree[1].right = 0;
	tree[1].left = &tree[11];


	tree[10].type = PIPECMD;
	tree[10].left = &tree[25];

	tree[11].type = PIPECMD;
	tree[11].left = &tree[27];


	tree[25].type = COMMAND;
	tree[25].left = &tree[50];
	tree[25].right = &tree[26];

	tree[26].type = COMMAND;
	tree[26].left = &tree[51];
	tree[26].right = 0;


	tree[27].type = COMMAND;
	tree[27].left = &tree[52];
	tree[27].right = &tree[28];

	tree[28].type = COMMAND;
	tree[28].left = &tree[53];
	tree[28].right = 0;


	tree[50].type = WORD;
	tree[50].content = ft_strdup("ls");

	tree[51].type = WORD;
	tree[51].content = ft_strdup("README");

	tree[52].type = WORD;
	tree[52].content = ft_strdup("echo");

	tree[53].type = WORD;
	tree[53].content = ft_strdup("!!!ECHO!!!");

	execute(&tree[0]);
	/* execlist1(&tree[90], fd, 0, 0); */
	/* execscmd(&tree[11], fd, 0, 0); */
	return (0);
}

/*
 * 	PIPES
 */

	/* tree[90].type = PIPECMD; */
	/* tree[90].left = &tree[0]; */

	/* tree[0].type = REST; */
	/* tree[0].right = &tree[1]; */
	/* tree[0].left = &tree[10]; */

	/* tree[1].type = PIPE; */
	/* tree[1].right = 0; */
	/* tree[1].left = &tree[11]; */


	/* tree[10].type = COMMAND; */
	/* tree[10].left = &tree[50]; */
	/* tree[10].right = 0; */

	/* tree[11].type = COMMAND; */
	/* tree[11].left = &tree[51]; */
	/* tree[11].right = &tree[25]; */

	/* tree[25].type = COMMAND; */
	/* tree[25].left = &tree[52]; */
	/* tree[25].right = 0; */


	/* tree[50].type = WORD; */
	/* tree[50].content = ft_strdup("ls"); */

	/* tree[51].type = WORD; */
	/* tree[51].content = ft_strdup("cat"); */

	/* tree[52].type = WORD; */
	/* tree[52].content = ft_strdup("-e"); */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:12:02 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/19 22:44:34 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	for (int i = 0; i < ac; i++)
		printf("av:%s\n", av[i]);
	for (; *env; env++)
		printf("en:%s\n", *env);
	return (0);
}

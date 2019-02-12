/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:12:02 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/11 20:25:56 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("ac:%d\n", ac);
	printf("av:%s\n", *av);
	printf("env:%s\n", *env);
	env = environ;
	while (*env)
		printf("%s\n", *env++);
	return (0);
}

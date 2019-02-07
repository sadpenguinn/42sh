/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:39:35 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 11:29:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"
#include "array.h"

int		main(void)
{
	array_add("abc", 3);
	array_add("abc", 3);
	array_add("abc\n", 4);
	/* array_flush(); */
	array_add("abc\n", 4);
	array_add("abc\n", 4);
	array_add("abc\n", 4);
	array_add("abc\n", 4);
	array_flush(1);
}

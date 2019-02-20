/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:01:56 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:32:01 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libhash.h"
#include "libft.h"

void		hash_print_cell(char *key, char *value)
{
	ft_putstr(key);
	ft_putchar('=');
	ft_putendl(value);
}

/*
** Just printing the table
*/

int 		hash_print(t_hash *hash)
{
	if ((hash_foreach(hash, hash_print_cell)) == HSH_ERR)
		return (HSH_ERR);
	ft_putstr(C_GREEN"Size: ");
	ft_putnbrendl((int)hash->size);
	ft_putstr("Filled: ");
	ft_putnbrendl((int)hash->filled);
	ft_putstr(C_DEFAULT);
	return (HSH_OK);


}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:10:47 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/25 18:11:23 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <string.h>

enum array_default_params
{
	ARRAY_DEFAULT_SIZE = 10,
	FACTOR = 2
};


typedef	struct		s_array
{
	char	*buf;
	size_t	len;
	size_t	size;
}					t_array;

void	array_add(const char *str, size_t len);
char	*array_to_string(void);
void	array_flush(void);

#endif

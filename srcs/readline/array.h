/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:44:45 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 09:08:23 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# define ARRAY_SIZE 10
# define FACTOR 2

typedef	struct	s_array
{
	char	*buf;
	int		len;
}				t_array;

void	array_add(const char *str, int len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:44:45 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 11:27:50 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# define DEFAULT_SIZE 10
# define FACTOR 2
# define ARR_LEN_LIMIT 0

typedef	struct		s_array
{
	char			*buf;
	unsigned int	len;
	unsigned int	size;
}					t_array;

void	array_add(const char *str, unsigned int len);
char *array_to_string(void);
void	array_flush(void);

#endif

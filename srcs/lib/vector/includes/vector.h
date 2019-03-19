/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 07:45:12 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/27 12:51:35 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <string.h>
# define ARR_SIZE 10
# define A 1.5

int			vector_to_array(void **vector);
void		*vector_get_elem(void *vector, size_t i);
int			vector_del_elem(void **vector, size_t i);
size_t		vector_get_len(void *vector);
int			vector_push_back(void **vector, const void *data);
int			vector_is_empty(void *vector);
void		*vector_front(void *vector);
int			vector_pop_back(void **vector);
void		vector_free(void **vector);
void		*vector_create(size_t elem_byte_size);
void		*vector_back(void *vector);
void		vector_foreach(void *vector, void (c)(void *));
long double	ft_ceill(long double x);
long double	ft_floorl(long double x);

#endif

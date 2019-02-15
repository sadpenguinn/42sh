/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:07:19 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/15 18:10:36 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_SHELL_H
#define INIT_SHELL_H

void	init_hash_env(char **env);
void	init_path(void);
int 	keyvaluecmp(void *el1, size_t cs1, void *el2, size_t cs2);

#endif

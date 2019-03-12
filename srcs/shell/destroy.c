/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:32:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:56:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	destroy(void)
{
	destroy_env();
	destroy_path();
	destroy_pids();
	destroy_jobs();
	destroy_aliases();
	destroy_functions();
	destroy_function_args();
}

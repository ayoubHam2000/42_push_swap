/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_smin_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:15:56 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 00:16:16 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	init_smin_size(t_stack *sa)
{
	int	i;

	i = 0;
	sa->util->sm_size = 0;
	while (i < sa->size - 1)
	{
		if (sa->s[i] != sa->s[i + 1] + 1)
			break ;
		i++;
	}
	if (sa->s[i] == 0)
		sa->util->sm_size = i + 1;
}

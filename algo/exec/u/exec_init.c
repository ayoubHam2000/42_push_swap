/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:04:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 00:33:50 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	exec_init(t_stack *sa, t_stack *sb)
{
	int	min;
	int	l;
	int	r;

	if (sa->util->sm_size != 0)
		return ;
	min = find_s_min(sa);
	l = min;
	r = sa->size - min - 1;
	if (l < r + 1)
		ft_exec(sa, sb, l, RRA);
	else
		ft_exec(sa, sb, r + 1, RA);
	sa->util->sm_size++;
}

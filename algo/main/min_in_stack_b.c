/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_in_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:40:56 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 23:09:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	min_in_stack_b(t_stack *sa, t_stack *sb)
{
	void	(*pf[5])(t_stack *sa, t_stack *sb);
	void	(*best)(t_stack *sa, t_stack *sb);
	int		i;
	int		old;

	pf[0] = exec_mb_1;
	pf[1] = exec_mb_2;
	pf[3] = exec_rmb_1;
	pf[4] = exec_rmb_2;
	i = -1;
	old = 0;
	while (++i < 5)
	{
		sa->util->moves = 0;
		pf[i](sa, sb);
		if (sa->util->moves != 0 && (sa->util->moves < old || old == 0))
		{
			old = sa->util->moves;
			best = pf[i];
		}
	}
	sa->util->affect = 1;
	best(sa, sb);
}

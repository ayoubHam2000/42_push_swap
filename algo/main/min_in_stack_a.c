/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_in_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:39:41 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/22 15:07:18 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#define MAX 6

static void	get_steps(void (**pf)(t_stack *sa, t_stack *sb))
{
	pf[0] = exec_ma_1;
	pf[1] = exec_ma_2;
	pf[2] = exec_rma_1;
	pf[3] = exec_rma_2;
	pf[4] = exec_rma_3;
	pf[5] = exec_rma_4;
}

void	min_in_stack_a(t_stack *sa, t_stack *sb)
{
	void	(*pf[MAX])(t_stack *sa, t_stack *sb);
	void	(*best)(t_stack *sa, t_stack *sb);
	int		i;
	float	density;

	get_steps(pf);
	i = -1;
	density = 0;
	while (++i < MAX)
	{
		sa->util->moves = 0;
		sa->util->density = 0;
		pf[i](sa, sb);
		if (sa->util->moves && (sa->util->density < density || !density))
		{
			density = sa->util->density;
			best = pf[i];
			//if (density <= 1)
			//	break ;
		}
	}
	sa->util->affect = 1;
	best(sa, sb);
}

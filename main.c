/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/23 11:33:15 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	push_swap(t_stack *sa, t_stack *sb)
{
	int	m;
	transform(sa);
	init_smin_size(sa);
	print_stack(*sa);

	int	i = 0;
	while (1)
	{
		if (sa->util->sm_size == sa->size + sb->size)
			break ;
		sa->util->affect = 0;
		m = find_s_min(sa);
		if (m != -1 && sa->s[m] == sa->util->sm_size)
			min_in_stack_a(sa, sb);
		else
			min_in_stack_b(sa, sb);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;
	t_util	*util;

	av++;
	init_stack(&sa, ac - 1, av, SA);
	init_stack(&sb, ac - 1, NULL, SB);
	util = init_util();
	sa.util = util;
	sb.util = util;
	if (sa.size > 1)
		push_swap(&sa, &sb);
	mem_clean();
	return (0);
}

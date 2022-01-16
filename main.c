/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 02:17:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"



//=============================
void	push_swap(t_stack *sa, t_stack *sb)
{
	transform(sa);
	init_smin_size(sa);
	sa->util->nbr_ele = sa->size;
	print_stack(*sa);
	
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
	push_swap(&sa, &sb);
	mem_clean();
	return (0);
}

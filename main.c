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

void	to_stack_b(t_stack *sa, t_stack *sb, t_list *lis)
{
	t_node	*node;

	node = lis->head;
	while (node)
	{
		
		node = node->next;
	}
}

t_list	*get_lis(t_list *lics)
{
	return (_LIST(lics->head));
}

void	push_swap(t_stack *sa, t_stack *sb)
{
	t_list	*lics;

	transform(sa);
	print_stack(*sa);
	lics = LICS(sa->s, sa->size);
	print_lists(lics);
}	

void	push(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;

	init_push(&sa, &sb, ac, av);	
	if (sa.size > 1)
		push_swap(&sa, &sb);
	free(sa.util);
}

int	main(int ac, char **av)
{
	push(ac, av);
	return (0);
}

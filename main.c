/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 22:32:38 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	find_right_pos(t_stack *sa, int b)
{
	return (1);
}

void	exec_best(t_stack *sa, t_stack *sb)
{
	int		i;
	int		right_pos;
	void	(*rule)(t_stack *sa, t_stack *sb, int a, int b);
	void	(*f)(t_stack *sa, t_stack *sb, int a, int b);
	int		old_moves;
	int		a;
	int		b;

	i = -1;
	sa->util->affect = 0;
	old_moves = 0;
	while (++i < sb->size)
	{
		right_pos = find_right_pos(sa, sb->s[i]);
		rule = get_best_rule(sa, sb, right_pos, sb->s[i]);
		sa->util->moves = 0;
		rule(sa, sb, right_pos, sb->s[i]);
		if (old_moves == 0 || old_moves > sa->util->moves)
		{
			old_moves = sa->util->moves;
			a = right_pos;
			b = sb->s[i];
			f = rule;
		}
	}
	sa->util->affect = 1;
	f(sa, sb, a, b);
}

void	to_stack_a(t_stack *sa, t_stack *sb)
{
	while (sa->util->sm_size != sa->size + sb->size)
	{
		exec_best(sa, sb);
		sa->util->sm_size++;
	}
}

void	push_swap(t_stack *sa, t_stack *sb)
{
	t_list	*lic;

	transform(sa);
	print_stack(*sa);
	lic = get_lis(LICS(sa->s, sa->size));
	print_list_nbr(lic);
	sa->util->affect = 1;
	sa->util->sm_size = lic->len;
	to_stack_b(sa, sb, lic);
	to_stack_a(sa, sb);
	l_delete_all(lic, NULL);
	free(lic);
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

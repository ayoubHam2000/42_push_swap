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
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 1;
	f = b > sa->s[0];
	while (i < sa->size)
	{
		if (sa->s[j] > sa->s[i] && ((sa->s[j] < b && sa->s[i] < b)
			|| (sa->s[j] > b && sa->s[i] > b)))
			return (i);
		else if (sa->s[j] < b && b < sa->s[i])
			return (i);
		f += b > sa->s[j];
		i++;
		j = (j + 1) % (sa->size);
	}
	if (!f || f == sa->size)
		return (sa->size - 1);
	return (-1);
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
		rule = get_best_rule(sa, sb, right_pos, i);
		sa->util->moves = 0;
		rule(sa, sb, right_pos, i);
		if (old_moves == 0 || old_moves > sa->util->moves)
		{
			old_moves = sa->util->moves;
			a = right_pos;
			b = i;
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

void	adjust(t_stack *sa, t_stack *sb)
{
	int	l;
	int	r;
	
	l = min_pos(sa);
	r = sa->size - l - 1;
	if (l + 1 < r)
		ft_exec(sa, sb, l + 1, RRA);
	else
		ft_exec(sa, sb, r, RA);
}

void	push_swap(t_stack *sa, t_stack *sb)
{
	t_list	*lic;

	transform(sa);
	print_stack(*sa);
	lic = LICS(sa->s, sa->size);
	print_lists(lic);
	lic = get_lis(lic);
	print_list_nbr(lic);
	sa->util->affect = 1;
	sa->util->sm_size = lic->len;
	to_stack_b(sa, sb, lic);
	to_stack_a(sa, sb);
	adjust(sa, sb);
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

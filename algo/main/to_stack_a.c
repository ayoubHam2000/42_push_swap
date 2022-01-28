/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:46:13 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:28:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static int	find_right_pos(t_stack *sa, int b)
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

static void	exec_best(t_stack *sa, t_stack *sb)
{
	int		i;
	int		right_pos;
	void	(*rule)(t_stack *sa, t_stack *sb, int a, int b);
	t_info	info;

	i = -1;
	sa->util->affect = 0;
	info.old_moves = 0;
	while (++i < sb->size)
	{
		right_pos = find_right_pos(sa, sb->s[i]);
		rule = get_best_rule(sa, sb, right_pos, i);
		sa->util->moves = 0;
		rule(sa, sb, right_pos, i);
		if (info.old_moves == 0 || info.old_moves > sa->util->moves)
		{
			info.old_moves = sa->util->moves;
			info.a = right_pos;
			info.b = i;
			info.f = rule;
		}
	}
	sa->util->affect = 1;
	info.f(sa, sb, info.a, info.b);
}

void	to_stack_a(t_stack *sa, t_stack *sb)
{
	while (sa->util->sm_size != sa->size + sb->size)
	{
		exec_best(sa, sb);
		sa->util->sm_size++;
	}
}

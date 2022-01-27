/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_rule.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:22:24 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/27 03:08:06 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	exec_rule1(t_stack *sa, t_stack *sb, int a, int b)
{
	int	ar;
	int	br;

	ar = sa->size - a - 1;
	br = sb->size - b - 1;
	ft_exec(sa, sb, ft_min(br, ar), RR);
	ft_exec(sa, sb, ar - ft_min(br, ar), RA);
	ft_exec(sa, sb, br - ft_min(br, ar), RB);
	ft_exec(sa, sb, 1, PA);
}

static void	exec_rule2(t_stack *sa, t_stack *sb, int a, int b)
{
	int	ar;

	ar = sa->size - a - 1;
	ft_exec(sa, sb, ar, RA);
	ft_exec(sa, sb, b + 1, RRB);
	ft_exec(sa, sb, 1, PA);
}

static void	exec_rule3(t_stack *sa, t_stack *sb, int a, int b)
{
	int	br;

	br = sb->size - b - 1;
	ft_exec(sa, sb, a + 1, RRA);
	ft_exec(sa, sb, br, RB);
	ft_exec(sa, sb, 1, PA);
}

static void	exec_rule4(t_stack *sa, t_stack *sb, int a, int b)
{
	int	al;

	al = a + 1;
	ft_exec(sa, sb, ft_min(b + 1, al), RRR);
	ft_exec(sa, sb, al - ft_min(b + 1, al), RRA);
	ft_exec(sa, sb, b + 1 - ft_min(b + 1, al), RRB);
	ft_exec(sa, sb, 1, PA);
}

void	*get_best_rule(t_stack *sa, t_stack *sb, int a, int b)
{
	void	(*p[4])(t_stack *sa, t_stack *sb, int a, int b);
	int		best;
	int		old;
	int		i;

	p[0] = exec_rule1;
	p[1] = exec_rule2;
	p[2] = exec_rule3;
	p[3] = exec_rule4;
	best = -1;
	old = 0;
	i = -1;
	while (++i < 4)
	{
		sa->util->moves = 0;
		p[i](sa, sb, a, b);
		if (best == -1 || (sa->util->moves < old))
		{
			old = sa->util->moves;
			best = i;
		}
	}
	return (p[best]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/20 23:42:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#pragma region y
void	exec_end(t_stack *s, t_m_info *i)
{
	if (i && i->me != -1)
		ft_free(i->si);
	if (s->util->affect)
		init_smin_size(s);
}

void	exec_rr_or_ra(t_stack *sa, t_stack *sb, int n)
{
	if (n > 0)
		ft_exec(sa, sb, 1, RR);
	else
		ft_exec(sa, sb, 1, RA);
}

void	exec_rmb_1(t_stack *sa, t_stack *sb)
{
	t_m_info	info;
	int			i;

	init_rm_info(&info, sb);
	if (info.me == -1)
		return (exec_end(sa, &info));
	ft_exec(sa, sb, info.si[0], RB);
	i = -1;
	while (++i < info.n - 1)
	{
		ft_exec(sa, sb, 1, PA);
		exec_rr_or_ra(sa, sb, info.si[1]);
		ft_exec(sa, sb, info.si[1] - 1, RB);
	}
	ft_exec(sa, sb, 1, PA | RA << 4);
	exec_end(sa, &info);
}

void	exec_rmb_2(t_stack *sa, t_stack *sb)
{
	t_m_info	info;
	int			i;

	init_rm_info(&info, sb);
	if (info.me == -1)
		return (exec_end(sa, &info));
	i = info.n + 1;
	while (--i >= 1)
	{
		ft_exec(sa, sb, info.si[i] + 1, RRB);
		ft_exec(sa, sb, 1, PA);
	}
	ft_exec(sa, sb, info.n, RA);
	exec_end(sa, &info);
}

void	exec_ma_1_part_2(t_stack *sa, t_stack *sb, t_m_info *info)
{
	int	i;

	ft_exec(sa, sb, info->si[1], SA | PB << 4);
	if (info->n == 3 && info->si[1] + info->si[2] == 1)
	{
		ft_exec(sa, sb, 1, SS);
		ft_exec(sa, sb, 2, RA);
		ft_exec(sa, sb, 1, PA | RA << 4);
		return ;
	}
	else
		ft_exec(sa, sb, 1, SA);
	i = sa->util->moves;
	ft_exec(sa, sb, 2, RA);
}

void	exec_ma_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	init_m_info(&info, sa);
	if (info.n == 1 && info.ms == sa->size - 1)
	{
		ft_exec(sa, sb, 1, RA);
		return exec_end(sa, NULL);
	}
	if (info.me == -1)
		return (exec_end(sa, &info));
	ft_exec(sa, sb, info.si[info.n], PB);
	if (info.n >= 2 && sa->s[sa->size - 1] + 1 == sa->s[sa->size - 2])
	{
		ft_exec(sa, sb, 1, SA);
		ft_free(info.si);
		init_m_info(&info, sa);
	}
	i = info.n;
	while (--i >= 2)
		ft_exec(sa, sb, info.si[i] + 1, PB);
	exec_ma_1_part_2(sa, sb, &info);
	exec_end(sa, &info);
}
#pragma endregion

void	exec_ma_2(t_stack *sa,t_stack *sb)
{
	int			i;
	t_m_info	info;
	int			mouves;
	
	init_m_info(&info, sa);
	if (info.me == -1)
		return (exec_end(sa, &info));
	mouves = cal_ma_2(sa);
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	ft_exec(sa, sb, info.si[0], RRA | PB << 4);
	ft_exec(sa, sb, 1, RRA);
	if (sa->util->sm_size == 1 && info.n == 1)
	{
		ft_exec(sa, sb, 1, SA | RA << 4 | RA << 8);
		return (exec_end(sa, &info));
	}
	i = 1;
	while (sa->util->moves + 2 * (i) + sa->util->sm_size + info.si[i] * 2 + 1 < mouves)
	{
		ft_exec(sa, sb, info.si[i], RRA | PB << 4);
		ft_exec(sa, sb, 1, RRA);
		i++;
	}
	if (sa->util->sm_size == 1 && info.n - i == 1)
	{
		ft_exec(sa, sb, 1, SA);
		ft_exec(sa, sb, 2, RA);
		return (exec_end(sa, &info));
	}
	ft_exec(sa, sb, i, PB);
	ft_exec(sa, sb, sa->util->sm_size, RA);
	ft_exec(sa, sb, i, PA | RA << 4);
	exec_end(sa, &info);
}

void	exec_mb_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	init_m_info(&info, sb);
	if (info.me == -1)
		return (exec_end(sa, &info));
	i = info.n + 1;
	while (--i > 0)
	{
		ft_exec(sa, sb, info.si[i], RB);
		ft_exec(sa, sb, 1, PA);
	}
	ft_exec(sa, sb, info.n, RA);
	exec_end(sa, &info);
}

void	exec_mb_2(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	init_m_info(&info, sb);
	if (info.me == -1)
		return (exec_end(sa, &info));
	i = -1;
	while (++i < info.n)
	{
		ft_exec(sa, sb, info.si[i] + 1, RRB);
		ft_exec(sa, sb, 1, PA | RA << 4);
	}
	exec_end(sa, &info);
}

void	exec_mb_3(t_stack *sa, t_stack *sb)
{
	if (sb->size == 1)
	{
		ft_exec(sa, sb, 1, PA | RA << 4);
		init_smin_size(sa);
	}
}

void	exec_rma_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	init_rm_info(&info, sa);
	if (info.me == -1)
		return (exec_end(sa, &info));
	i = -1;
	while (++i < info.n)
	{
		ft_exec(sa, sb, info.si[i], PB);
		ft_exec(sa, sb, 1, RA);
	}
	exec_end(sa, &info);	
}

void	exec_rma_2(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	int			a;
	
	init_rm_info(&info, sa);
	if (info.me == -1)
		return (exec_end(sa, &info));
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	a = sa->s[info.me] - sa->s[a];
	ft_exec(sa, sb, info.si[0], PB);
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	i = info.n + 1;
	while (--i >= a)
	{
		ft_exec(sa, sb, info.si[i], RRA | PB << 4);
		if (i != a)
			ft_exec(sa, sb, 1, RRA);
	}
	ft_exec(sa, sb, a, RA);
	exec_end(sa, &info);
}

void	exec_rma_3(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	int			a;
	
	init_rm_info(&info, sa);
	if (info.me == -1)
		return (exec_end(sa, &info));
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	a = sa->s[info.me] - sa->s[a];
	ft_exec(sa, sb, info.si[0], PB);
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	i = info.n + 1;
	while (--i >= a)
	{
		ft_exec(sa, sb, info.si[i], RRA);
		if (i != a)
			ft_exec(sa, sb, 1, RRA | PB << 4);		
	}
	ft_exec(sa, sb, a, PA | RA << 4);
	exec_end(sa, &info);
}

void	exec_rma_4(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	init_rm_info(&info, sa);
	if (info.me == -1)
		return (exec_end(sa, &info));
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	i = info.n + 1;
	while (--i >= 1)
	{
		ft_exec(sa, sb, info.si[i], RRA | PB << 4);
		ft_exec(sa, sb, 1, RRA);
		if (sa->util->sm_size == 1)
			ft_exec(sa, sb, 1, SA);
	}
	if (sa->util->sm_size == 1)
	{
		//ft_exec(sa, sb, 2, RA);
		if (info.si[0] < info.n + 1)
			ft_exec(sa, sb, info.si[i], RRA);
		else
			ft_exec(sa, sb, info.n + 1, RA);
	}
	else
	{
		ft_exec(sa, sb, info.n, PB);
		ft_exec(sa, sb, sa->util->sm_size, RA);
		ft_exec(sa, sb, info.n, PA);
		ft_exec(sa, sb, info.n, RA);
	}
	exec_end(sa, &info);
}

void	exec_a_init(t_stack *sa, t_stack *sb)
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

//=============================

void	min_in_stack_a(t_stack *sa, t_stack *sb)
{
	void	(*pf[6])(t_stack *sa, t_stack *sb);
	void	(*best)(t_stack *sa, t_stack *sb);
	int		i;
	int		old;

	pf[0] = exec_ma_1;
	pf[1] = exec_ma_2;
	pf[2] = exec_rma_1;
	pf[3] = exec_rma_2;
	pf[4] = exec_rma_3;
	pf[5] = exec_rma_4;
	i = -1;
	old = 0;
	while (++i < 6)
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

void	min_in_stack_b(t_stack *sa, t_stack *sb)
{
	void	(*pf[5])(t_stack *sa, t_stack *sb);
	void	(*best)(t_stack *sa, t_stack *sb);
	int		i;
	int		old;

	pf[0] = exec_mb_1;
	pf[1] = exec_mb_2;
	pf[2] = exec_mb_3;
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

void	push_swap(t_stack *sa, t_stack *sb)
{
	int	m;
	transform(sa);
	init_smin_size(sa);
	print_stack(*sa);
	exec_a_init(sa, sb);
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

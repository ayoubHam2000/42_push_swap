/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/17 01:53:26 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	exec_ma_1_rr_or_ra(t_stack *sa, t_stack *sb, int n)
{
	if (n > 0)
		ft_exec(sa, sb, 1, RR);
	else
		ft_exec(sa, sb, 1, RA);
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
	i = 2;
	while (--i >= 0)
		exec_ma_1_rr_or_ra(sa, sb, info->si[1] + info->si[2]);
	ft_exec(sa, sb, ft_max(0, info->si[1] + info->si[2] - 2), RB);
	i = 2;
	while (++i < info->n)
	{
		ft_exec(sa, sb, 1, PA);
		exec_ma_1_rr_or_ra(sa, sb, info->si[i]);
		ft_exec(sa, sb, ft_max(0, info->si[i] - 1), RB);
	}
	ft_exec(sa, sb, 1, PA | RA << 4);
}

void	exec_ma_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	init_m_info(&info, sa);
	ft_exec(sa, sb, info.si[info.n], PB);
	if (info.n == 1)
	{
		ft_exec(sa, sb, 1, RA);
		return ;
	}
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
	if (info.old_moves > sa->util->moves)
		sa->util->p = &exec_ma_1;
	sa->util->moves = 0;
	ft_free(info.si);
}

//=============================
void	push_swap(t_stack *sa, t_stack *sb)
{
	transform(sa);
	init_smin_size(sa);
	sa->util->nbr_ele = sa->size;
	print_stack(*sa);
	
	sa->util->moves = -1;
	exec_ma_1(sa, sb);
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

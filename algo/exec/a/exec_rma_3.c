/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rma_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:57:38 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 22:28:44 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	sep_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, 1, RA);
	exec_end(sa, info);	
}

static void sep_2(t_stack *sa, t_stack *sb, t_m_info *info, int i)
{

	ft_exec(sa, sb, 2, RRA);
	ft_exec(sa, sb, 2, PB);
	info->si[i - 1]--;
	info->n++;
}

void	exec_rma_3(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	int			a;
	
	if (!init_rm_info(&info, sa))
		return ;
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	a = sa->s[a] - sa->s[info.ms];
	ft_exec(sa, sb, info.si[0], PB);
	if (info.n == 1)
		return (sep_1(sa, sb, &info));
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	i = info.n + 1;
	while (--i > a)
	{
		ft_exec(sa, sb, info.si[i], RRA);
		if (i != a + 1 && sa->s[0] + 1 == sa->s[1])
			sep_2(sa, sb, &info, i);
		else if (i != a + 1)
			ft_exec(sa, sb, 1, RRA | PB << 4);
	}
	ft_exec(sa, sb, info.n - a - 1, PA | RA << 4);
	exec_end(sa, &info);
}

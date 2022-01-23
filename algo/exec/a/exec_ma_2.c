/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ma_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:55:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/22 12:44:44 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static int	cal_best_min(t_stack *sa, t_m_info *info)
{
	int	res;
	int	i;
	int	added_mouves;
	int	mins;
	
	res = 2 * info->ms + 4;
	if (sa->util->sm_size == 1)
		res--;
	i = 0;
	added_mouves = 0;
	mins = 1;
	while (i < info->n - 1)
	{
		added_mouves += 2 * seq_m_si(sa, i + 1) + 4;
		i++;
		if ((res + added_mouves) / (float)(i + 1) <= res / (float)(i))
		{
			res += added_mouves;
			added_mouves = 0;
			mins++;
		}
	}
	return (mins);
}

static void	sep_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, 1, SA);
	ft_exec(sa, sb, 2, RA);
	ft_exec(sa, sb, info->n - 1, PA | RA << 4);
	exec_end(sa, info);
}

static void	part_2(t_stack *sa, t_stack *sb, t_m_info *info, int i)
{
	if (sa->util->sm_size == 0)
	{
		ft_exec(sa, sb, i - 2, PB);
		ft_exec(sa, sb, 1, SA);
		ft_exec(sa, sb, 2, RA);
		ft_exec(sa, sb, i - 2, PA | RA << 4);
		return (exec_end(sa, info));
	}
	else
		ft_exec(sa, sb, i - 1, PB);
	if (sa->util->sm_size == 1)
		return (sep_1(sa, sb, info));
	else
		ft_exec(sa, sb, 1, PB);
	ft_exec(sa, sb, sa->util->sm_size, RA);
	ft_exec(sa, sb, i, PA | RA << 4);
	exec_end(sa, info);
}

void	exec_ma_2(t_stack *sa,t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	if(!init_m_info(&info, sa))
		return ;
	info.n = cal_best_min(sa, &info);
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	ft_exec(sa, sb, info.si[0], RRA | PB << 4);
	ft_exec(sa, sb, 1, RRA);
	i = 0;
	while (++i < info.n)
	{
		ft_exec(sa, sb, info.si[i], RRA | PB << 4);
		ft_exec(sa, sb, 1, RRA);
	}
	part_2(sa, sb, &info, i);
}

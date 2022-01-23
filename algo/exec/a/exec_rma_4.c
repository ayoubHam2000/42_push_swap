/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rma_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:57:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/22 14:27:22 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	spe_1(t_stack *sa, t_stack *sb, t_m_info *info, int i)
{
	int	j;

	j = info->si[0];
	if (info->n >= 3 && sa->s[j] + 1 == sa->s[j + 1])
	{
		if (info->n - 1 < info->si[0] + 2)
			ft_exec(sa, sb, info->n - 1, RA);
		else
			ft_exec(sa, sb, info->si[0] + 2, RRA);
		ft_exec(sa, sb, 1, SA);
		ft_exec(sa, sb, 2, RA);
	}
	else
	{
		if (info->si[0] < info->n + 1)
			ft_exec(sa, sb, info->si[i], RRA);
		else
			ft_exec(sa, sb, info->n + 1, RA);	
	}
	exec_end(sa, info);
}

static void	spe_2(t_stack *sa, t_stack *sb, t_m_info *info, int i)
{
	if (!sa->util->sm_size && info->n == 1)
		return ;
	if (sa->s[0] + 1 == sa->s[1])
	{
		if (sa->util->sm_size != 1)
		{
			ft_exec(sa, sb, 2, RRA);
			ft_exec(sa, sb, 1, SA);
			if (!sa->util->sm_size && sa->s[sa->size - 1] == 0)
				ft_exec(sa, sb, 1, RA);
		}
		else
			ft_exec(sa, sb, 2, RRA | SA << 4);
		info->si[i - 1]--;
		info->n++;
	}
	else
	{
		if (i == 1 && !sa->util->sm_size)
			return ; 
		ft_exec(sa, sb, 1, RRA);
		if (sa->util->sm_size == 1)
			ft_exec(sa, sb, 1, SA);
	}
}

static void	spe_3(t_stack *sa, t_stack *sb, t_m_info *info)
{
	if (!sa->util->sm_size)
		return (exec_end(sa, info));
	ft_exec(sa, sb, sa->util->sm_size, SA | RA << 4);
	ft_exec(sa, sb, 1, RA);
	exec_end(sa, info);
}

static void	spe_4(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, info->n, PB);
	ft_exec(sa, sb, sa->util->sm_size, RA);
	ft_exec(sa, sb, info->n, PA);
	ft_exec(sa, sb, info->n, RA);
}

void	exec_rma_4(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	if(!init_rm_info(&info, sa))
		return ;
	ft_exec(sa, sb, sa->util->sm_size, RRA);
	i = info.n + 1;
	while (--i >= 1)
	{
		if (info.n == 1 && !sa->util->sm_size)
			ft_exec(sa, sb, info.si[i], RRA);
		else
			ft_exec(sa, sb, info.si[i], RRA | PB << 4);
		spe_2(sa, sb, &info, i);
	}
	if (sa->util->sm_size == 1)
		return (spe_1(sa, sb, &info, i));
	else if (info.n == 1)
		return (spe_3(sa, sb, &info));
	if (sa->util->sm_size != 0)
		spe_4(sa, sb, &info);
	else
		ft_exec(sa, sb, info.n - 1, RA);
	exec_end(sa, &info);
}

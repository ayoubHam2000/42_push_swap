/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ma_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:06:12 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 20:09:37 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	sep_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	if (info->si[1] == 0)
		ft_exec(sa, sb, 1, RA);
	else
	{
		ft_exec(sa, sb, info->si[1] - 1, PB);
		ft_exec(sa, sb, 1, SA | RA << 4);
	}
	return exec_end(sa, info);
}

static void	exec_ma_1_part_2(t_stack *sa, t_stack *sb, t_m_info *info)
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
	ft_exec(sa, sb, 2, RA);
	i = 1;
	while (++i < info->n)
	{
		if (i == 2)
			ft_exec(sa, sb, info->si[2] + info->si[1], RB);
		else
			ft_exec(sa, sb, info->si[i], RB);
		ft_exec(sa, sb, 1, PA | RA << 4);
	}
}

void	exec_ma_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	if (!init_m_info(&info, sa))
		return ;
	if (info.n == 1)
		return (sep_1(sa, sb, &info));
	ft_exec(sa, sb, info.si[info.n], PB);
	if (sa->s[sa->size - 1] + 1 == sa->s[sa->size - 2])
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

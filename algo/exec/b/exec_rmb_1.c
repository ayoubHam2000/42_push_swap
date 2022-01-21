/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rmb_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:00:11 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 23:39:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	spe_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, 1, PA | RA << 4);
	exec_end(sa, info);
}

static void	spe_2(t_stack *sa, t_stack *sb, t_m_info *info, int i)
{
	int	j;

	j = sb->size - info->si[i] - 1;
	if (j + 1 < sb->size && sb->s[j] + 1 == sb->s[j + 1])
	{
		ft_exec(sa, sb, info->si[i] - 1, RB);
		ft_exec(sa, sb, 1, SB);
		ft_exec(sa, sb, 2, PA | RA << 4);
		info->n++;
	}
	else
	{
		ft_exec(sa, sb, info->si[i], RB);
		ft_exec(sa, sb, 1, PA | RA << 4);
	}
}

void	exec_rmb_1(t_stack *sa, t_stack *sb)
{
	t_m_info	info;
	int			i;

	if (!init_rm_info(&info, sb))
		return ;
	if (sb->size == 1)
		return (spe_1(sa, sb, &info));
	i = -1;
	while (++i < info.n - 1)
	{
		ft_exec(sa, sb, info.si[i], RB);
		ft_exec(sa, sb, 1, PA | RA << 4);
	}
	spe_2(sa, sb, &info, i);
	exec_end(sa, &info);
}

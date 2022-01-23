/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mb_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:59:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/22 12:52:29 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	spe_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, 1, PA | RA << 4);
	exec_end(sa, info);
}

void	exec_mb_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	if (!init_m_info(&info, sb))
		return ;
	if (sb->size == 1)
		return (spe_1(sa, sb, &info));
	i = info.n + 1;
	while (--i > 0)
	{
		ft_exec(sa, sb, info.si[i], RB);
		if (sb->size >= 2 && sb->s[sb->size - 1] + 1 == sb->s[sb->size - 2])
		{
			ft_exec(sa, sb, 1, SB);
			ft_exec(sa, sb, 2, PA);
			info.si[i - 1]--;
			info.n++;
		}
		else
			ft_exec(sa, sb, 1, PA);
	}
	ft_exec(sa, sb, info.n, RA);
	exec_end(sa, &info);
}

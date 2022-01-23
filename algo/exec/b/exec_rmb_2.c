/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rmb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:00:15 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/22 09:19:39 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	spe_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, 1, PA | RA << 4);
	exec_end(sa, info);
}

void	exec_rmb_2(t_stack *sa, t_stack *sb)
{
	t_m_info	info;
	int			i;

	if(!init_rm_info(&info, sb))
		return ;
	if (sb->size == 1)
		return (spe_1(sa, sb, &info));
	i = info.n + 1;
	while (--i >= 1)
	{
		ft_exec(sa, sb, info.si[i], RRB);
		if (i == info.n && sb->size > 1 && sb->s[0] + 1 == sb->s[1])
		{
			ft_exec(sa, sb, 2, RRB);
			ft_exec(sa, sb, 2, PA);
			info.n++;
			info.si[i - 1]--;
		}
		else
			ft_exec(sa, sb, 1, RRB | PA << 4);
	}
	ft_exec(sa, sb, info.n, RA);
	exec_end(sa, &info);
}

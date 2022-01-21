/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mb_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:00:03 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 23:06:48 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	spe_1(t_stack *sa, t_stack *sb, t_m_info *info)
{
	ft_exec(sa, sb, 1, PA | RA << 4);
	exec_end(sa, info);
}

void	exec_mb_2(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	if (!init_m_info(&info, sb))
		return ;
	if (sb->size == 1)
		return (spe_1(sa, sb, &info));
	i = -1;
	while (++i < info.n)
	{
		if (sb->size > 1 && sb->s[0] == sb->s[1] + 1)
		{
			ft_exec(sa, sb, 2, RRB);
			ft_exec(sa, sb, 2, PA | RA << 4);
			info.n++;
			i++;
		}
		else
		{
			ft_exec(sa, sb, info.si[i] + 1, RRB);
			ft_exec(sa, sb, 1, PA | RA << 4);
		}
	}
	exec_end(sa, &info);
}

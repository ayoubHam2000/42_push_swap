/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rm_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:00:15 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 00:01:22 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

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

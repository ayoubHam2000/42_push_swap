/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rma_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:56:24 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 04:40:14 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	exec_rma_1(t_stack *sa, t_stack *sb)
{
	int			i;
	t_m_info	info;
	
	if (!init_rm_info(&info, sa))
		return ;
	i = -1;
	while (++i < info.n - 1)
	{
		ft_exec(sa, sb, info.si[i], PB);
		ft_exec(sa, sb, 1, RA);
	}
	ft_exec(sa, sb, info.si[i] - 1, PB);
	if (info.si[i] >= 1 && sa->s[sa->size - 1] == sa->s[sa->size - 2] + 1)
	{
		ft_exec(sa, sb, 1, SA | RA << 4);
		info.n++;
	}
	else if(info.si[i] >= 1)
		ft_exec(sa, sb, 1, PB);
	ft_exec(sa, sb, 1, RA);
	exec_end(sa, &info);	
}

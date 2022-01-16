/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:21:45 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 01:22:59 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

//SB = S_n m_n ... S_1 m_1 SR
//sr + sum(1 + 1) + sum(0, n, max(s_i - 1))
int	cal_rmb_1(t_stack *sb)
{
	int			res;
	t_m_info	info;
	int			i;

	init_rm_info(&info, sb);
	res = 2 * info.min_nbr;
	res += sb->size - info.ms - 1;
	i = -1;
	while (++i < info.min_nbr)
		res += ft_max(0, seq_rm_si(sb, i) - 1);
	return (res);
}

//sum(s_i) + sum(2) + sum(1)
int	cal_rmb_2(t_stack *sb)
{
	int			res;
	t_m_info	info;

	init_rm_info(&info, sb);
	res = 3 * info.min_nbr;
	res += info.ms + 1 - info.min_nbr;
	return (res);
}

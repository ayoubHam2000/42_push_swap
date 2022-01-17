/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:21:46 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 22:08:26 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

//sum(1 + 1) + sum(s_i)
int	cal_mb_1(t_stack *sb)
{
	int			res;
	t_m_info	info;

	init_m_info(&info, sb);
	res = info.n;
	res += sb->size - info.ms;
	return (res);
}

//SL + 2n + 1 + if(n>1)sum(0, n-1, 1 * if(s_i + 2 < S_A)) + sum(s_i)
int	cal_mb_2(t_stack *sb)
{
	int			res;
	t_m_info	info;
	int			i;

	init_m_info(&info, sb);
	res = info.ms;
	res += 3 * info.n;
	res += info.me - info.ms + 1 - info.n;
	i = -1;
	/*while (++i < info.n - 1)
		if (seq_m_si(sb, i) + 2 < sb->util->nbr_ele - sb->size)
			res += 1;*/
	return (res);
}

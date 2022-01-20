/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:05 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/17 03:51:36 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

//if n>1 :3(n-1) + s1 + (sa-P_m1-n) + Min(0, s_2-2) + sum(3, n, Min(0, S_i-1))
//if n==1:s1 + 1
//3 -> 4 -> 0 -> 5 -> 1 -> 8 -> 2 -> 7 -> 6
int	cal_ma_1(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			i;

	res = 0;
	init_m_info(&info, sa);
	if (info.ms == -1)
		return (-1);
	if (info.n == 1)//4
		return (seq_m_si(sa, 0) + 1);
	else if (info.n == 2)
		return (seq_m_si(sa, 1) + 2 * seq_m_si(sa, 0) + 3);
	res = 3 * (info.n - 1) + seq_m_si(sa, 0);
	res += sa->size - info.ms - info.n;
	res += ft_max(0, seq_m_si(sa, 1) + seq_m_si(sa, 0) - 2);
	i = 1;
	while (++i < info.n - 1)
		res += ft_max(0, seq_m_si(sa, i) - 1);
	return (res);
}

//2 * ms + 4 + sum(0, n-1, (2 * s_i + 4) * (is it good))
//ms + 2 * s_l + 4
int	cal_ma_2(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			i;
	int			added_mouves;
	
	init_m_info(&info, sa);
	if (sa->util->sm_size == 1 && info.n == 1)
		return (2 * info.ms - sa->util->sm_size + 4);
	res = 2 * info.ms + 4;
	i = 0;
	added_mouves = 0;
	while (i < info.n - 1)
	{
		added_mouves += 2 * seq_m_si(sa, i + 1) + 4;
		i++;
		if ((res + added_mouves) / (float)(i + 1) <= res / (float)(i))
		{
			res += added_mouves;
			added_mouves = 0;
		}
	}
	return (res);
}

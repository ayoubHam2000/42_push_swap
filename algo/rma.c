/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rma.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:10 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 22:08:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

////sr = SA - P_m_1 - 1
int	cal_rma_1(t_stack *sa)
{
	int			res;
	t_m_info	info;

	init_rm_info(&info, sa);
	res = sa->size - info.me;
	return (res);
}

int	cal_rma_2(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			a;

	init_rm_info(&info, sa);
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	res = sa->size - info.ms - 1;
	res += sa->util->sm_size;
	a = sa->s[info.me] - sa->s[a];
	if (a == 0)
		return (res + seq_rm_si(sa, info.n - 1));
	res += 2 * a;
	a++;
	while (--a >= 0)
		res += 2 * seq_rm_si(sa, info.n - a - 1);
	return (res);
}

int	cal_rma_3(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			a;

	init_rm_info(&info, sa);
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	res = sa->size - info.ms - 1;
	res += sa->util->sm_size;
	a = sa->s[info.me] - sa->s[a];
	res += 4 * a;
	a++;
	while (--a >= 0)
		res += seq_rm_si(sa, info.n - a - 1);
	return (res);
}

int	cal_rma_4(t_stack *sa)
{
	int			res;
	t_m_info	info;

	init_rm_info(&info, sa);
	if (sa->util->sm_size == 1)
		return (2 * (info.ms + 1) + info.n);
	res = 2 * (info.n + info.ms + 1);
	return (res);
}

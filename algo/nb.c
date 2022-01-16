/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:23:55 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 01:37:42 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	cal_nb_1_ma1(t_stack *sa, t_stack *sb)
{
	int			res;
	t_m_info	info;

	init_m_info(&info, sa);
	res = 0;
	if (info.min_nbr == 1)
		res -= 2;
	else
		res += sa->size - info.ms - 1 - 2 * info.min_nbr;
	res += cal_mb_1(sb);
	return (res);
}

int	cal_nb_1_ma2(t_stack *sa, t_stack *sb)
{
	t_m_info	info;

	init_m_info(&info, sa);
	return (cal_mb_1(sb) - info.min_nbr);
}

int	cal_nb_2_rma1(t_stack *sb)
{
	return (cal_mb_2(sb));
}

int	cal_nb_2_rma2(t_stack *sa, t_stack *sb)
{
	t_m_info	info;
	int			res;

	init_rm_info(&info, sa);
	res = cal_mb_2(sb);
	res -= info.ms + info.min_nbr;
	return (res);
}

int	cal_nb_2_rma3(t_stack *sa, t_stack *sb)
{
	t_m_info	info;
	int			res;

	init_rm_info(&info, sa);
	res = cal_mb_2(sb);
	res -= info.ms + 1;
	return (res);
}

int	cal_nb_2_rma4(t_stack *sb)
{
	return (cal_mb_2(sb));
}


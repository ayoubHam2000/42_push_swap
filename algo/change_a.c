/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 07:42:09 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/10 20:31:41 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_left_a(t_stack *sa)
{
	int	i;

	//printf("Left A\n");
	i = sa->minPos;
	while (i > 0)
	{
		ft_rra(sa);
		i--;
	}
	sa->minPos = -1;	
}

void	change_right_a(t_stack *sa)
{
	int	i;

	//printf("Right A\n");
	i = sa->size - sa->minPos;
	while (i > 0)
	{
		ft_ra(sa);
		i--;
	}
	sa->minPos = -1;	
}

/*
SA = SM.SL.m.SR
SB = SL.m.SR

SA = SL.m.SR.SM //SM
SB = SL.m.SR 

SA = SR.SM //SM + SL + SL + 1 + 1
SB = SL.m.SR.RSL.m

SA = m.SM.SR //2.SM + 2.SL + 2 + 2
SB = SL.m.SR.RSL

N = SL
2.SL <= LEN + N

*/

void	change__left_a(t_stack *sa, t_stack *sb)
{
	int	i;
	int	sm;
	int	sl;
	int	flag;

	//printf("_Left A\n");
	sm = find_sm_size(sa);
	sl = sa->minPos - sm;
	i = sa->minPos;
	flag = 0;
	if (2 * sb->minPos <= sb->size + sl)
		flag = 1;
	else if (sb->minPos != -1)
		flag = 2;
	while (i > 0)
	{
		if (flag == 1 && sb->minPos > 0)
			ft_rrr(sa, sb);
		else
			ft_rra(sa);
		if (i <= sl)
			ft_pb(sa, sb);
		i--;
	}
	if (flag == 1 && sb->minPos > 0)
		ft_rrr(sa, sb);
	else
		ft_rra(sa);
	if (sm == 1)
	{
		ft_sa(sa);
		i = 2;
		while (--i >= 0)
		{
			if (flag == 2 && sb->minPos < sb->size - 1)
				ft_rr(sa, sb);
			else
				ft_ra(sa);
		}
	}
	else
	{
		ft_pb(sa, sb);
		i = sm;
		while (--i >= 0)
		{
			if (flag == 2 && sb->minPos < sb->size - 1)
				ft_rr(sa, sb);
			else
				ft_ra(sa);
		}
		ft_pa(sa, sb);
		if (flag == 2 && sb->minPos < sb->size - 1)
			ft_rr(sa, sb);
		else
			ft_ra(sa);
	}
	sa->minPos = -1;
}

void	change__right_a(t_stack *sa, t_stack *sb)
{
	int	i;
	int	flag;

	//printf("_Right A\n");
	i = sa->size - sa->minPos - 1;
	if (sa->minPos == sa->size - 2)
	{
		ft_sa(sa);
		if (2 * (sb->minPos + 1) >= sb->size && sb->minPos != -1)
			ft_rr(sa, sb);
		else
			ft_ra(sa);
		sa->minPos = -1;
		return ;
	}
	flag = 0;
	if (2 * (sb->minPos + 1) >= sb->size + i)
		flag = 1;
	while (i > 0)
	{
		ft_pb(sa, sb);
		i--;
	}
	if (flag && sb->minPos < sb->size - 1)
		ft_rr(sa, sb);
	else
		ft_ra(sa);
	sa->minPos = -1;
}

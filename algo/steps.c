/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 04:59:18 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/10 20:32:05 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_from_sa(t_stack *sa, t_stack *sb)
{
	int	d;

	d = direction(sa);
	if (d == LEFT)
		change_left_a(sa);
	else if (d == RIGHT)
		change_right_a(sa);
	else if (d == _LEFT)
		change__left_a(sa, sb);
	else if (d == _RIGHT)
		change__right_a(sa, sb);
	return (d);
}

void	sort_from_sb(t_stack *sa, t_stack *sb)
{
	int	d;

	d = direction(sb);
	if (d == LEFT)
		change_left_b(sa, sb);
	else if (d == RIGHT)
		change_right_b(sa, sb);
}

int	step(t_stack *sa, t_stack *sb)
{
	int	f;
	int m_sa;
	int	m_sb;

	find_next_min(sa, sb);
	//printf("min(%d, %d, %d)\n", sa->minPos, find_sm_size(sa), sb->minPos);
	f = 1;
	if (sa->minPos == -1 && sb->minPos == -1)
		return (-1);
	m_sa = sa->s[sa->minPos];
	m_sb = sb->s[sb->minPos];
	if ((m_sa < m_sb && sa->minPos != -1) || (sa->minPos != -1 && sb->minPos == -1))
		f = sort_from_sa(sa, sb);
	else if ((m_sb < m_sa && sb->minPos != -1) || (sa->minPos == -1 && sb->minPos != -1))
		sort_from_sb(sa, sb);
	return (f);
}

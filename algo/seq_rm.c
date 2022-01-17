/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 22:08:59 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	seq_rm_mi(t_stack *s, int i)
{
	int	c;
	int	mi;
	
	mi = find_s_min(s);
	if (s->s[mi] != s->util->sm_size)
		return (-1);
	c = mi - 1;
	while (c >= 0 && (i > 0 || i <= -1))
	{
		if (s->s[mi] + 1 == s->s[c])
		{
			mi = c;
			i--;
		}
		c--;
	}
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

//from [0 to n[
int	seq_rm_si(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = seq_rm_mi(s, i);
	m2 = seq_rm_mi(s, i + 1);
	if (m2 == -1)
		return (m1 - s->util->sm_size);
	return (m1 - m2 - 1);
}

int	init_rm_info(t_m_info *info, t_stack *s)
{
	info->ms = seq_rm_mi(s, 0);
	info->me = seq_rm_mi(s, -1);
	info->n = s->s[info->me] - s->util->sm_size + 1;
}

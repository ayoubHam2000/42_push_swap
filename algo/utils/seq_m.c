/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:16 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 02:24:34 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	seq_m_mi(t_stack *s, int i)
{
	int	c;
	int	mi;
	
	mi = find_s_min(s);
	if (mi == -1 || s->s[mi] != s->util->sm_size)
		return (-1);
	c = mi + 1;
	while (c < s->size && (i > 0 || i <= -1))
	{
		if (s->s[mi] + 1 == s->s[c])
		{
			mi = c;
			i--;
		}
		c++;
	}
	if (i == -1 && mi == find_s_min(s))
		return (-1);
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

//from [0 to n[
int	seq_m_si(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = seq_m_mi(s, i - 1);
	m2 = seq_m_mi(s, i);
	if (i == 0)
	{
		if (s->tag == SA)
			return (m2 - s->util->sm_size);
		return (m2);
	}
	if (m2 == -1)
		return (s->size - m1 - 1);
	return (m2 - m1 - 1);
}

int	init_m_info(t_m_info *info, t_stack *s)
{
	int	i;
	
	info->ms = seq_m_mi(s, 0);
	info->me = seq_m_mi(s, -1);
	if (info->ms == -1)
		return (0);
	if (info->me == -1)
		info->n = 1;
	else
		info->n = s->s[info->me] - s->s[info->ms] + 1;
	info->si = ft_malloc(sizeof(int) * (info->n + 1));
	i = -1;
	while (++i < info->n + 1)
		info->si[i] = seq_m_si(s, i);
	return (1);
}


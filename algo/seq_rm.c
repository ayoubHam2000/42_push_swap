/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:22 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/20 23:13:32 by aben-ham         ###   ########.fr       */
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
	if (i == -1 && mi == find_s_min(s))
		return (-1);
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

int	seq_rm_si(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = seq_rm_mi(s, i - 1);
	m2 = seq_rm_mi(s, i);
	if (i == 0)
		return (s->size - m2 - 1);
	if (m2 == -1)
	{
		if (s->tag == SA)
			return (m1 - s->util->sm_size);
		return (m1);
	}
	return (m1 - m2 - 1);
}

void	init_rm_info(t_m_info *info, t_stack *s)
{
	int	i;

	info->ms = seq_rm_mi(s, 0);
	info->me = seq_rm_mi(s, -1);
	if (info->me == -1 && info->ms != -1)
		info->n = 1;
	if (info->me == -1)
		return ;
	info->n = s->s[info->me] - s->util->sm_size + 1;
	info->old_moves = s->util->moves;
	info->si = ft_malloc(sizeof(int) * (info->n + 1));
	i = -1;
	while (++i < info->n + 1)
		info->si[i] = seq_rm_si(s, i);
}

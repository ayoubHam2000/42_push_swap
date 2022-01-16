/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:41:16 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/16 01:19:09 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int	seq_m_mi(t_stack *s, int i)
{
	int	c;
	int	mi;
	
	mi = find_s_min(s);
	if (s->s[mi] != s->util->sm_size)
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
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

//from [0 to min_nbr[
int	seq_m_si(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = seq_m_mi(s, i);
	m2 = seq_m_mi(s, i + 1);
	if (m2 == -1)
		return (s->size - m1 - 1);
	return (m2 - m1 - 1);
}

void	init_m_info(t_m_info *info, t_stack *s)
{
	info->ms = seq_m_mi(s, 0);
	info->me = seq_m_mi(s, -1);
	info->min_nbr = s->s[info->me] - s->util->sm_size + 1;
}


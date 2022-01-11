/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:00:29 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/10 12:45:35 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
SA = SM.S
SB = L
size(SM) >= 0
size(S) >= 1
size(SB) >= 0
*/

int	find_min_index(t_stack *s, int start)
{
	int	i;
	int	index;
	
	if (start <= -1)
		start = 0;
	i = start + 1;
	index = start;
	if (i > s->size)
		return (-1);
	while (i < s->size)
	{
		if (s->s[index] > s->s[i])
			index = i;
		i++;
	}
	return (index);
}

int	find_sm_size(t_stack *s)
{
	int	min_index;
	int	i;

	min_index = find_min_index(s, 0);
	i = min_index - 1;
	if (min_index == -1)
		return (-1);
	while (i >= 0)
	{
		if (s->s[i] < s->s[i + 1])
			return (0);
		i--;
	}
	return (min_index + 1);
}

int	find_s_min(t_stack *s)
{
	int	sm_size;

	if (s->tag == SB)
		return (find_min_index(s, 0));
	sm_size = find_sm_size(s);
	//if (sm_size == s->size)
	//	return (-1);
	return (find_min_index(s, sm_size));
}

void	find_next_min(t_stack *sa, t_stack *sb)
{
	if (sa->minPos == -1)
		sa->minPos = find_s_min(sa);
	if (sb->minPos == -1)
		sb->minPos = find_s_min(sb);
}

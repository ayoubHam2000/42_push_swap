/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:19:05 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/10 12:56:37 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	direction(t_stack *s)
{
	int	sm_size;

	if (s->tag == SA)
		sm_size = find_sm_size(s);
	if (s->tag == SB)
	{
		if (2 * (s->minPos + 1) < s->size)
			return (LEFT);
		else
			return (RIGHT);
	}
	if (sm_size == 0)
	{
		if (s->minPos <= s->size - s->minPos)
			return (LEFT);
		else
			return (RIGHT);
	}
	if (sm_size == s->size)
		return (-1);
	if (3 * s->minPos + 4 <= s->size)
		return (_LEFT);
	else
		return (_RIGHT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_s_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:14:50 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 00:14:59 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static int	find_min_form(t_stack *s, int start)
{
	int	i;
	int	res;

	if (start >= s->size)
		return (-1);
	i = start + 1;
	res = start;
	while (i < s->size)
	{
		if (s->s[res] > s->s[i])
			res = i;
		i++;
	}
	return (res);
}

int	find_s_min(t_stack *s)
{
	if (s->tag == SA)
		return (find_min_form(s, s->util->sm_size));
	return (find_min_form(s, 0));
}

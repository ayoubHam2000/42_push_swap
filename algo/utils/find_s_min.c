/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_s_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:14:50 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:28:52 by aben-ham         ###   ########.fr       */
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

int	min_pos(t_stack *s)
{
	return (find_min_form(s, 0));
}

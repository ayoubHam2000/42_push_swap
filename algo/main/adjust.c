/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:50:59 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:28:26 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	adjust(t_stack *sa, t_stack *sb)
{
	int	l;
	int	r;

	l = min_pos(sa);
	r = sa->size - l - 1;
	if (l + 1 < r)
		ft_exec(sa, sb, l + 1, RRA);
	else
		ft_exec(sa, sb, r, RA);
}

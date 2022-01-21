/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:04:18 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/21 03:13:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	exec_end(t_stack *s, t_m_info *i)
{
	if (!i || !i->n)
		return ;
	ft_free(i->si);
	if (s->util->affect)
		s->util->sm_size += i->n;
	else
		s->util->density = s->util->moves / (float)i->n;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:24:34 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 14:32:02 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	l_default_del_ptr(void	*p)
{
	free(p);
}

void	l_del_node(t_node *node, void (*del_ptr)(void *p))
{
	if (!node)
		return ;
	if (del_ptr)
		del_ptr(node->p);
	else
		l_default_del_ptr(node->p);
	free(node);
}

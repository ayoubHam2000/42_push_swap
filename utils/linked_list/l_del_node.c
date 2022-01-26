/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_del_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:24:34 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 23:24:34 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	l_delete_simple(t_node *node)
{
	free(node->p);
	free(node);
}

void	l_del_node(t_node *node, void (*del)(t_node *node))
{
	if (!node)
		return ;
	if (del)
		del(node);
	else
		l_delete_simple(node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_node_del.c                                       :+:      :+:    :+:   */
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
	ft_free(node->p);
	ft_free(node);
}

void	l_node_del(t_node *node, void	(*del)(t_node *node))
{
	if (!node)
		return ;
	if (del)
		del(node);
	else
		l_delete_simple(node);
}

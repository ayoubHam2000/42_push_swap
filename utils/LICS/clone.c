/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:54:12 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/25 11:54:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

t_node	*clone_nbr(t_node *node)
{
	t_node	*new_node;

	new_node = l_create_node(NULL);
	new_node->p = ft_malloc(sizeof(int));
	_INT(new_node) = _INT(node);
	return (new_node);
}

t_node	*clone_list_nbr(t_node *node)
{
	t_node	*new_node;

	new_node = l_create_node(NULL);
	new_node->p = l_clone(_LIST(node), clone_nbr);
	return (new_node);
}

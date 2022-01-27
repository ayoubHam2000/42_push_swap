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
	new_node->p = node->p;
	return (new_node);
}

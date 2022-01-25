/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:08:20 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 19:08:20 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	*l_init()
{
	t_list	*new_list;

	new_list = ft_malloc(sizeof(t_list));
	new_list->head = NULL;
	new_list->len = 0;
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:24:37 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 20:24:37 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

void	print_list_nbr(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	printf("[");
	while (tmp)
	{
		printf("%d", _INT(tmp));
		tmp = tmp->next;
		if (tmp)
			printf(", ");
	}
	printf("]\n");
}

void	print_lists(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		print_list_nbr(_LIST(tmp));
		tmp = tmp->next;
	}
}

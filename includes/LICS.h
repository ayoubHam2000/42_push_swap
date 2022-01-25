/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LICS.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:55:47 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 17:55:47 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LICS_H
# define LICS_H

# include "linked_list.h"
# include "stdio.h"

# define _INT(x) (*(int *)x->p)
# define _LIST(x) ((t_list *)x->p)


void	del_list_nbr(t_node *node);
void	del_same_len(t_list *lists, t_list *new);

void	*create_list();
void	*create_nbr(int nbr);

t_node	*clone_nbr(t_node *node);
t_node	*clone_list_nbr(t_node *node);

void	print_list_nbr(t_list *list);
void	print_lists(t_list *list);


void	lis_case1(t_list *lists, int n);
void	lis_case2(t_list *lists, int n);
void	lis_case3(t_list *lists, int n);
t_list	*LIS(int arr[], int size);

#endif

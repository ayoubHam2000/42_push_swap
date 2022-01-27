/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LICS.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:55:47 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 00:29:36 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LICS_H
# define LICS_H

# include "linked_list.h"
# include "stdio.h"

int		_int(t_node *x);
t_list	*_list(t_node *x);

void	del_list_nbr(t_node *node);
void	del_same_len(t_list *lists, t_list *new);

void	*create_nbr(int nbr);

t_node	*clone_nbr(t_node *node);

void	print_list_nbr(t_list *list);
void	print_lists(t_list *list);

void	lis_case1(t_list *lists, int n);
void	lis_case2(t_list *lists, int n);
void	lis_case3(t_list *lists, int n);
void	keep_longest(t_list *lists);
t_list	*lis(int *arr, int size);
t_list	*lics(int *arr, int size);

#endif

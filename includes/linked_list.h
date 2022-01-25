/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:12 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 19:02:12 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "ft_mem.h"

typedef struct s_node t_node;
struct s_node
{
	void	*p;
	t_node	*next;
};

typedef struct s_list t_list;
struct s_list
{
	t_node	*head;
	size_t	len;
};

void	*l_init();
t_node	*l_create_node(void *p);
size_t	l_len(t_list *list);
t_node	*l_get(t_list *list, int pos);
void	l_append_front(t_list *list, void *p);
void	l_append_end(t_list *list, void *p);
t_list	*l_clone(t_list *list, t_node *(*clone)(t_node *node));
void	l_del_node(t_node *node, void (*del)(t_node *node));
void	l_delete_all(t_list *list, void	(*del)(t_node *node));
void	l_delete_index(t_list *list, size_t index, void (*del)(t_node *node));
void	l_delete_node(t_list *list, t_node *node, void (*del)(t_node *node));

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:12 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 22:54:53 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_mem.h"

typedef struct s_node	t_node;
struct s_node
{
	void	*p;
	t_node	*next;
};

typedef struct s_list	t_list;
struct s_list
{
	t_node	*head;
	t_node	*last;
	long	len;
};

long	l_len(t_list *list);
void	*l_init(void);

t_node	*l_get(t_list *list, long pos);

t_node	*l_create_node(void *p);
void	l_append_front(t_list *list, void *p);
void	l_append_end(t_list *list, void *p);

t_list	*l_clone(t_list *list, void *(*clone_ptr)(void *p));

void	l_del_node(t_node *node, void (*del_ptr)(void *p));
void	l_del_by_prev(t_list *list, t_node *prev, void (*del_ptr)(void *p));
void	l_del_by_index(t_list *list, long index, void (*del_ptr)(void *p));
void	l_del_all(t_list *list, void (*del_ptr)(void *p));
void	l_del_cond(t_list *lists,
			void *p,
			int (*condition)(t_node *node, void *p),
			void (*del_ptr)(void *p));

#endif

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


void	del_less_than_n(t_list *lists, int n);

void	*create_list(size_t data_size);
void	*create_nbr(int nbr);

void	print_list_nbr(t_list *list);
void	print_lists(t_list *list);

#endif

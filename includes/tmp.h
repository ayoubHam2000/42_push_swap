/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 00:35:33 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 20:49:00 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMP_H
# define TMP_H

# include "algo.h"

void	print_list_nbr(t_list *list);
void	print_lists(t_list *list);
int		*get_arr(int ac, char **av);
void	print_stack(t_stack s);
int		check_sort(t_stack *sa);

#endif

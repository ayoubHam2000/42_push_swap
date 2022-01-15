/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:37:22 by ayoub             #+#    #+#             */
/*   Updated: 2022/01/15 02:30:04 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

typedef struct	s_m_info
{
	int	ms;
	int	me;
	int	min_nbr;
}	t_m_info;

/* ./algo/done.c */
void	*transform(t_stack *sa);

#endif
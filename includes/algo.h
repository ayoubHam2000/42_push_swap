/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:37:22 by ayoub             #+#    #+#             */
/*   Updated: 2022/01/21 23:09:14 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "LICS.h"
# include "push_swap.h"

typedef struct	s_m_info
{
	int	ms;
	int	me;
	int	n;
	int	old_moves;
	int	*si;
}	t_m_info;

void    *transform(t_stack *sa);
void    init_smin_size(t_stack *sa);

int     seq_m_mi(t_stack *s, int i);
int     seq_m_si(t_stack *s, int i);
int		init_m_info(t_m_info *info, t_stack *s);

int     seq_rm_mi(t_stack *s, int i);
int     seq_rm_si(t_stack *s, int i);
int		init_rm_info(t_m_info *info, t_stack *s);

int     find_s_min(t_stack *s);

void    exec_init(t_stack *sa, t_stack *sb);
void    exec_end(t_stack *s, t_m_info *i);

void    exec_ma_1(t_stack *sa, t_stack *sb);
void    exec_ma_2(t_stack *sa,t_stack *sb);
void    exec_rma_1(t_stack *sa, t_stack *sb);
void    exec_rma_2(t_stack *sa, t_stack *sb);
void    exec_rma_3(t_stack *sa, t_stack *sb);
void    exec_rma_4(t_stack *sa, t_stack *sb);

void    exec_mb_1(t_stack *sa, t_stack *sb);
void    exec_mb_2(t_stack *sa, t_stack *sb);
void    exec_rmb_1(t_stack *sa, t_stack *sb);
void    exec_rmb_2(t_stack *sa, t_stack *sb);

void	min_in_stack_a(t_stack *sa, t_stack *sb);
void	min_in_stack_b(t_stack *sa, t_stack *sb);

#endif

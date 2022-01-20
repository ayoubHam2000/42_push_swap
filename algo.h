/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:37:22 by ayoub             #+#    #+#             */
/*   Updated: 2022/01/17 06:33:23 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

typedef struct	s_m_info
{
	int	ms;
	int	me;
	int	n;
	int	old_moves;
	int	*si;
}	t_m_info;

void	*transform(t_stack *sa);
int		find_s_min(t_stack *s);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	init_smin_size(t_stack *sa);

int		seq_m_mi(t_stack *s, int i);
int		seq_m_si(t_stack *s, int i);
void	init_m_info(t_m_info *info, t_stack *s);

int		seq_rm_mi(t_stack *s, int i);
int		seq_rm_si(t_stack *s, int i);
void	init_rm_info(t_m_info *info, t_stack *s);

int		cal_ma_1(t_stack *sa);
int		cal_ma_2(t_stack *sa);

int		cal_rma_1(t_stack *sa);
int		cal_rma_2(t_stack *sa);
int		cal_rma_3(t_stack *sa);
int		cal_rma_4(t_stack *sa);

int	cal_mb_1(t_stack *sb);
int	cal_mb_2(t_stack *sb);

int	cal_rmb_1(t_stack *sb);
int	cal_rmb_2(t_stack *sb);

int	cal_nb_1_ma1(t_stack *sa, t_stack *sb);
int	cal_nb_1_ma2(t_stack *sa, t_stack *sb);
int	cal_nb_2_rma1(t_stack *sb);
int	cal_nb_2_rma2(t_stack *sa, t_stack *sb);
int	cal_nb_2_rma3(t_stack *sa, t_stack *sb);
int	cal_nb_2_rma4(t_stack *sb);


#endif
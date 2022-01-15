/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:35:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/15 22:52:25 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#pragma region done

int	find_min_form(t_stack *s, int start)
{
	int	i;
	int	res;

	if (start >= s->size)
		return (-1);
	i = start + 1;
	res = start;
	while (i < s->size)
	{
		if (s->s[res] > s->s[i])
			res = i;
		i++;
	}
	return (res);
}

int	find_s_min(t_stack *s)
{
	if (s->tag == SA)
		return (find_min_form(s, s->util->sm_size));
	return (find_min_form(s, 0));
}

int	min_nbr(t_stack *s, int me)
{
	return (s->s[me] - s->util->sm_size + 1);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	init_smin_size(t_stack *sa)
{
	int	i;

	i = 0;
	while (i < sa->size - 1)
	{
		if (sa->s[i] < sa->s[i + 1])
			break ;
		i++;
	}
	if (sa->s[i] == 0)
		sa->util->sm_size = i + 1;
}

#pragma endregion

#pragma region sma
int	find_mi(t_stack *s, int i)
{
	int	c;
	int	mi;
	
	mi = find_s_min(s);
	if (s->s[mi] != s->util->sm_size)
		return (-1);
	c = mi + 1;
	while (c < s->size && (i > 0 || i <= -1))
	{
		if (s->s[mi] + 1 == s->s[c])
		{
			mi = c;
			i--;
		}
		c++;
	}
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

//from [0 to min_nbr[
int	size_of_msi(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = find_mi(s, i);
	m2 = find_mi(s, i + 1);
	if (m2 == -1)
		return (s->size - m1 - 1);
	return (m2 - m1 - 1);
}

int	ms_left(t_stack *s, int ms)
{
	return (ms - s->util->sm_size);
}

void	init_m_info(t_m_info *info, t_stack *s)
{
	info->ms = find_mi(s, 0);
	info->me = find_mi(s, -1);
	info->min_nbr = min_nbr(s, info->me);
}

//if n>1 :3(n-1) + s1 + (sa-P_m1-n) + Min(0, s_2-2) + sum(3, n, Min(0, S_i-1))
//if n==1:s1 + 1
//3 -> 4 -> 0 -> 5 -> 1 -> 8 -> 2 -> 7 -> 6
int	cal_ma_1(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			i;

	res = 0;
	init_m_info(&info, sa);
	if (info.ms == -1)
		return (-1);
	if (info.min_nbr == 1)
		return (size_of_msi(sa, 0) + 1);
	else if (info.min_nbr == 2)
		return (size_of_msi(sa, 1) + 2 * size_of_msi(sa, 0) + 3);
	res = 3 * (info.min_nbr - 1) + size_of_msi(sa, 0);
	res += sa->size - info.ms - info.min_nbr;
	res += ft_max(0, size_of_msi(sa, 1) + size_of_msi(sa, 0) - 2);
	i = 1;
	while (++i < info.min_nbr - 1)
		res += ft_max(0, size_of_msi(sa, i) - 1);
	return (res);
}

//2 * ms + 4 + sum(0, n-1, (2 * s_i + 4) * (is it good))
//ms + 2 * s_l + 4
int	cal_ma_2(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			i;
	int			added_mouves;
	
	init_m_info(&info, sa);
	if (sa->util->sm_size == 1 && info.min_nbr == 1)
		return (2 * info.ms - sa->util->sm_size + 4);
	res = 2 * info.ms + 4;
	i = 0;
	added_mouves = 0;
	while (i < info.min_nbr - 1)
	{
		added_mouves += 2 * size_of_msi(sa, i) + 4;
		i++;
		if ((res + added_mouves) / (float)(i + 1) <= res / (float)(i))
		{
			res += added_mouves;
			added_mouves = 0;
		}
	}
	return (res);
}
#pragma endregion

#pragma region sna

int	find_rmi(t_stack *s, int i)
{
	int	c;
	int	mi;
	
	mi = find_s_min(s);
	if (s->s[mi] != s->util->sm_size)
		return (-1);
	c = mi - 1;
	while (c >= 0 && (i > 0 || i <= -1))
	{
		if (s->s[mi] + 1 == s->s[c])
		{
			mi = c;
			i--;
		}
		c--;
	}
	if (i == 0 || i <= -1)
		return (mi);
	else
		return (-1);
}

//from [0 to min_nbr[
int	size_rmsi(t_stack *s, int i)
{
	int	m1;
	int	m2;

	m1 = find_rmi(s, i);
	m2 = find_rmi(s, i + 1);
	if (m2 == -1)
		return (m1 - s->util->sm_size);
	return (m1 - m2 - 1);
}

int	init_rm_info(t_m_info *info, t_stack *s)
{
	info->ms = find_rmi(s, 0);
	info->me = find_rmi(s, -1);
	info->min_nbr = min_nbr(s, info->me);
}

////sr = SA - P_m_1 - 1
int	cal_rma_1(t_stack *sa)
{
	int			res;
	t_m_info	info;

	init_rm_info(&info, sa);
	res = sa->size - info.me;
	return (res);
}

int	cal_rma_2(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			a;

	init_rm_info(&info, sa);
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	res = sa->size - info.ms - 1;
	res += sa->util->sm_size;
	a = sa->s[info.me] - sa->s[a];
	if (a == 0)
		return (res + size_rmsi(sa, info.min_nbr - 1));
	res += 2 * a;
	a++;
	while (--a >= 0)
		res += 2 * size_rmsi(sa, info.min_nbr - a - 1);
	return (res);
}

int	cal_rma_3(t_stack *sa)
{
	int			res;
	t_m_info	info;
	int			a;

	init_rm_info(&info, sa);
	a = info.ms;
	while (a > 0 && sa->s[a - 1] == sa->s[a] + 1)
		a--;
	res = sa->size - info.ms - 1;
	res += sa->util->sm_size;
	a = sa->s[info.me] - sa->s[a];
	res += 4 * a;
	a++;
	while (--a >= 0)
		res += size_rmsi(sa, info.min_nbr - a - 1);
	return (res);
}

int	cal_rma_4(t_stack *sa)
{
	int			res;
	t_m_info	info;

	init_rm_info(&info, sa);
	if (sa->util->sm_size == 1)
		return (2 * (info.ms + 1) + info.min_nbr);
	res = 2 * (info.min_nbr + info.ms + 1);
	return (res);
}

#pragma endregion

//=============================

void	push_swap(t_stack *sa, t_stack *sb)
{
	transform(sa);
	init_smin_size(sa);
	print_stack(*sa);

	printf("ms = %d\n", find_rmi(sa, 0));
	printf("m2 = %d\n", find_rmi(sa, 1));
	printf("m3 = %d\n", find_rmi(sa, 2));
	printf("me = %d\n", find_rmi(sa, -1));
	
	printf("s_1 = %d\n", size_rmsi(sa, 0));
	printf("s_2 = %d\n", size_rmsi(sa, 1));
	printf("s_2 = %d\n", size_rmsi(sa, 2));
	
	printf("rma_1 = %d\n", cal_rma_1(sa));
	printf("rma_2 = %d\n", cal_rma_2(sa));
	printf("rma_3 = %d\n", cal_rma_3(sa));
	printf("rma_4 = %d\n", cal_rma_4(sa));
}

int	main(int ac, char **av)
{
	t_stack	sa;
	t_stack	sb;
	t_util	*util;

	av++;
	init_stack(&sa, ac - 1, av, SA);
	init_stack(&sb, ac - 1, NULL, SB);
	util = init_util();
	sa.util = util;
	sb.util = util;
	push_swap(&sa, &sb);
	mem_clean();
	return (0);
}

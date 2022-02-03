/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instrinction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:09:04 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/03 14:31:06 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 == (unsigned char)*s2 && *s1 != 0)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	get_instrinction(char *instrinction)
{
	if (!ft_strcmp(instrinction, "sa\n"))
		return (SA);
	else if (!ft_strcmp(instrinction, "sb\n"))
		return (SB);
	else if (!ft_strcmp(instrinction, "ss\n"))
		return (SS);
	else if (!ft_strcmp(instrinction, "pa\n"))
		return (PA);
	else if (!ft_strcmp(instrinction, "pb\n"))
		return (PB);
	else if (!ft_strcmp(instrinction, "ra\n"))
		return (RA);
	else if (!ft_strcmp(instrinction, "rb\n"))
		return (RB);
	else if (!ft_strcmp(instrinction, "rr\n"))
		return (RR);
	else if (!ft_strcmp(instrinction, "rra\n"))
		return (RRA);
	else if (!ft_strcmp(instrinction, "rrb\n"))
		return (RRB);
	else if (!ft_strcmp(instrinction, "rrr\n"))
		return (RRR);
	return (0);
}

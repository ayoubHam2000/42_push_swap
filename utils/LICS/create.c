/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:28:24 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 20:28:24 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LICS.h"

void	*create_nbr(int nbr)
{
	int	*p;

	p = ft_malloc(sizeof(int));
	*p = nbr;
	return (p);
}

void	*create_list()
{
	return (l_init());
}

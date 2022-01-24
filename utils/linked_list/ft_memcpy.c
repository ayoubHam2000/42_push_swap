/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:07:33 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/24 22:07:33 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src && n)
		return (NULL);
	d = dst;
	s = src;
	while (n-- > 0)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}

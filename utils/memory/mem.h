/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:21:13 by ayoub             #+#    #+#             */
/*   Updated: 2022/01/14 20:12:21 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_addresses
{
	void	**adds;
	size_t	size;
}	t_addresses;

void	mem_clean(void);
void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
void	*ft_mem_error(void);

#endif

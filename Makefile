# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:35:59 by aben-ham          #+#    #+#              #
#    Updated: 2022/01/09 04:47:00 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I.
FILES = utils/push.c \
		utils/reverse_rotate.c \
		utils/rotate.c \
		utils/stack.c \
		utils/swap.c \
		utils/utils.c \
		algo/*.c
all:
	gcc $(CFLAGS) main.c $(FILES) -o push_swap.out
dis:
	gcc $(CFLAGS) display.c $(FILES) -o dis_push_swap.out


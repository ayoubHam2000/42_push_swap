# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 00:30:00 by ayoub             #+#    #+#              #
#    Updated: 2021/12/29 01:48:19 by ayoub            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
FILES = utils/push.c \
		utils/reverse_rotate.c \
		utils/rotate.c \
		utils/stack.c \
		utils/swap.c \
		utils/utils.c
all:
	gcc $(CFLAGS) main.c $(FILES) -o push_swap.out
dis:
	gcc $(CFLAGS) display.c $(FILES) -o dis_push_swap.out


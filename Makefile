# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 00:30:00 by ayoub             #+#    #+#              #
#    Updated: 2021/12/28 00:39:48 by ayoub            ###   ########.fr        #
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

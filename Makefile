# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:35:59 by aben-ham          #+#    #+#              #
#    Updated: 2022/01/28 22:51:25 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Wall -Wextra -Werror
#DEBUG = -fdiagnostics-color=always -g
CFLAGS =  -Wall -Wextra -Werror -I includes/
FILES = \
		utils/other/*.c \
		utils/push_swap/*.c \
		utils/LICS/*.c \
		utils/linked_list/*.c \
		algo/main/*.c \
		algo/utils/*.c 

all:
	gcc $(CFLAGS) main.c $(FILES) -o push_swap.exe

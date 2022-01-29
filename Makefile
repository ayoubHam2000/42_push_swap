# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:35:59 by aben-ham          #+#    #+#              #
#    Updated: 2022/01/29 11:55:35 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Wall -Wextra -Werror
#DEBUG = -fdiagnostics-color=always -g
#ls -d algo/main/* algo/utils/* utils/push_swap/* utils/other/* utils/linked_list/* utils/LICS/* | grep "" | sed 's/$/ \\/'
CFLAGS =  -Wall -Wextra -Werror -I includes/
NAME = push_swap
FILES = \
		algo/main/adjust.c \
		algo/main/get_best_rule.c \
		algo/main/get_lis.c \
		algo/main/to_stack_a.c \
		algo/main/to_stack_b.c \
		algo/utils/find_s_min.c \
		utils/LICS/clone.c \
		utils/LICS/create.c \
		utils/LICS/delete.c \
		utils/LICS/lics.c \
		utils/LICS/lis.c \
		utils/LICS/type.c \
		utils/linked_list/l_append_end.c \
		utils/linked_list/l_append_front.c \
		utils/linked_list/l_clone.c \
		utils/linked_list/l_create_node.c \
		utils/linked_list/l_del_all.c \
		utils/linked_list/l_del_by_index.c \
		utils/linked_list/l_del_by_prev.c \
		utils/linked_list/l_del_cond.c \
		utils/linked_list/l_del_node.c \
		utils/linked_list/l_get.c \
		utils/linked_list/l_init.c \
		utils/linked_list/l_len.c \
		utils/other/ft_atoi.c \
		utils/other/ft_error.c \
		utils/other/ft_malloc.c \
		utils/other/ft_max.c \
		utils/other/ft_min.c \
		utils/push_swap/checker.c \
		utils/push_swap/ft_exec.c \
		utils/push_swap/push.c \
		utils/push_swap/reverse_rotate.c \
		utils/push_swap/rotate.c \
		utils/push_swap/stack.c \
		utils/push_swap/swap.c \
		main.c

INCLUDES = \
	includes/LICS.h \
	includes/algo.h \
	includes/ft_mem.h \
	includes/linked_list.h \
	includes/push_swap.h 


OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(patsubst %.o, %.d, $(OBJ))
-include $(deps)

DEPFLAGS = -MMD -MF $(@:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : obj/%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:obj/%.o=%.c) $(DEPFLAGS) -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 19:01:55 by harndt            #+#    #+#              #
#    Updated: 2022/08/31 23:58:38 by harndt           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# VARIABLES
# ==============================================================================

NAME		:=	minitalk
BINARY		:=	client server
CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra
HEADERS		:=	includes
LIBFT		:=	./libft/libft.a
SRCS		:=	./srcs/client.c	./srcs/server.c
OBJS		:=	$(SRCS:.c=.o)

# ==============================================================================
# COLORS
# ==============================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RULES
# ==============================================================================

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(BINARY)

$(LIBFT):
			@echo "$(WHT)Compiling libft...$(EOC)"
			@make -C libft
			@echo "$(GREEN)Libft done.$(EOC)"

client:		srcs/client.o $(LIBFT)
			@$(CC) $(CFLAGS) ./srcs/client.o -I $(HEADERS) $(LIBFT) -o $@
			@echo "$(GREEN)Client compiled.$(EOC)"

server:		srcs/server.o $(LIBFT)
			@$(CC) $(CFLAGS) ./srcs/server.o -I $(HEADERS) $(LIBFT) -o $@
			@echo "$(GREEN)Server compiled.$(EOC)"

clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@make -C libft clean
			@echo "$(GREEN)MINITALK - Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object and binary files...$(EOC)"
			@rm -f $(BINARY)
			@make -C libft fclean
			@echo "$(GREEN)MINITALK - Fclean done.$(EOC)"

re:			fclean all

valgrind:
			@echo "$(WHT)Removing old log.$(EOC)"
			@rm -f valgrind-out.txt
			@echo "$(WHT)Old log removed.$(EOC)"
			@echo "$(WHT)Executing Valgrind.$(EOC)"
			@valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes \
			--log-file=valgrind-out.txt \
			./server
			@echo "$(GREEN)Valgrind-log created.$(EOC)"

.PHONY:		all clean fclean re valgrind
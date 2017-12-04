# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 18:37:17 by kwiessle          #+#    #+#              #
#    Updated: 2017/12/04 16:42:17 by vquesnel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= computor
LOGIN= COME_GARIN

SRCS= src/main.c \
			src/error.c \
			src/parser.c \
			src/math.c \
			src/print.c \
			src/test.c \
			src/graph.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx -lm
FLAGS= -Wall -Wextra -Werror 
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\033[38;5;79m  [$(NAME)]	Compiled."
	@echo "\033[34m"
	@echo "\033[38;5;84m  MMMºººAMV '7MMºººYb.   '7MMºººMq. "
	@echo "  M'   AMV    MM    'Yb.   MM   'MM."
	@echo "\033[38;5;85m  '   AMV     MM     'Mb   MM   ,M9 "
	@echo "     AMV      MM      MM   MMmmdM9  "
	@echo "\033[38;5;86m    AMV   ,   MM     ,MP   MM"
	@echo "   AMV   ,M   MM    ,dP'   MM"
	@echo "\033[38;5;87m  AMVmmmmMM .JMMmmmdP'   .JMML. "
	@echo ""
	@echo "\033[38;5;7m [2018]                    [${LOGIN}]"
	@echo ""

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OBJS)
	@echo "\033[38;5;174m  [$(NAME)]	Objects destroyed.\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[38;5;174m  [$(NAME)]	Binary removed.\033[0m"

re:		fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 18:37:17 by kwiessle          #+#    #+#              #
#    Updated: 2017/11/30 13:41:59 by vquesnel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= computor
LOGIN= ZDTEAM

SRCS= src/main.c \
			src/error.c \
			src/parser.c \
			src/math.c \
			src/print.c \
			test.c \

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes
LIBS= -L libft/ -lft
FLAGS= -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	@make -C libft/
	@gcc -o $(NAME) $(OBJS) $(LIBS)
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
	@rm -f $(OBJS)
	@echo "\033[38;5;174m  [$(NAME)]	Objects destroyed.\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[38;5;174m  [$(NAME)]	Binary removed.\033[0m"

re:		fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 18:37:17 by kwiessle          #+#    #+#              #
#    Updated: 2017/11/27 10:36:46 by kwiessle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= computor

SRCS= src/main.c \
			src/error.c \
			src/parser.c \
			src/math.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes
LIBS= -L libft/ -lft
FLAGS= -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	@make -C libft/
	@gcc -o $(NAME) $(OBJS) $(LIBS)
	@echo "\033[34m"
	@echo "  MMMºººAMV '7MMºººYb.   '7MMºººMq. "
	@echo "  M'   AMV    MM    'Yb.   MM   'MM."
	@echo "  '   AMV     MM     'Mb   MM   ,M9 "
	@echo "     AMV      MM      MM   MMmmdM9  "
	@echo "    AMV   ,   MM     ,MP   MM"
	@echo "   AMV   ,M   MM    ,dP'   MM"
	@echo "  AMVmmmmMM .JMMmmmdP'   .JMML. "
	@echo "\033[37m"
	@echo " [ZDTEAM]                    [2018]"
	@echo ""

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "\033[32mall $(NAME)_files.o are deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[33m$(NAME) is deleted\033[0m"

re:		fclean all

.PHONY: all clean fclean re

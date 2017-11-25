# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 18:37:17 by kwiessle          #+#    #+#              #
#    Updated: 2017/11/24 21:08:40 by kwiessle         ###   ########.fr        #
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
	@echo "		\033[31;1m"
	@echo "		  ,__________,  ,____________,     "
	@echo "		  |          |  |             \    "
	@echo "		  |____.     |  |    ,___,     \   "
	@echo "		      /     /   |    |    \     \  "
	@echo "		     /     /    |    |     \     \ "
	@echo "		    /_____/     |____|     /     / "
	@echo "		  ,______________________./     /  "
	@echo "		  |                            /   "
	@echo "		  |__________________________./    "
	@echo "\033[0m"
	@echo "		  ZDTEAM                   2016"
	@echo "\n"


$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS)
	@echo "\033[37mall $(NAME)_files.o are deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:		fclean all

.PHONY: all clean fclean re

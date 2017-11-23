# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 18:37:17 by kwiessle          #+#    #+#              #
#    Updated: 2017/11/23 22:35:51 by kwiessle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= computor

SRCS= src/main.c \
			src/error.c \
			src/math.c

OBJS= $(SRCS:.c=.o)
INCLUDES=  -I includes
FLAGS= -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	@gcc -o $(NAME) $(OBJS)
	@echo "		\033[49;1m"
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
	@rm -f $(OBJS)
	@echo "\033[37mall FdF_files.o are deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:		fclean all

.PHONY: all clean fclean re

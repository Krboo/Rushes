# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atheveno <atheveno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 15:50:06 by atheveno          #+#    #+#              #
#*   Updated: 2015/12/10 05:22:47 by mnicolas         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME =		alum1
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
LDLIBS =	-lft
RM =		/bin/rm -rf
SRC =
OBJ =		$(SRC:.c=.o)
EXT =		$(NAME:.a=.h)
EXT	+=		Makefile

SRC += main.c read_file.c algo.c ia.c print.c

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(CFLAGS) -c $(SRC) -I ./include
	@echo "Objects created" 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "Program created"

clean:
	@echo "Objects are being removed ..." 
	@$(RM) $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "$(NAME) is being removed ..."
	@$(RM) $(OBJ) $(NAME)
	@make -C libft/ fclean

re: fclean all

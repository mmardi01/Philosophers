# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmardi <mmardi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 11:33:53 by mmardi            #+#    #+#              #
#    Updated: 2022/06/19 14:49:02 by mmardi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror

FILES = ./Mandatory/fill.c ./Mandatory/ft_philo.c \
		./Mandatory/philo.c ./Mandatory/utils.c \

HEADER = ./Mandatory/philo.h

OBJ = $(FILES:.c=.o)


all: $(NAME)
$(NAME) : $(HEADER) $(OBJ) 
		$(CC) $(CFLAGS) $(FILES) -o $(NAME)

clean:
	@rm -rf $(OBJ) 

fclean: clean
	@rm -rf $(NAME)

re: fclean all

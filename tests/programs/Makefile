# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:20:08 by vvaucoul          #+#    #+#              #
#    Updated: 2022/04/12 15:45:30 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_01 = test_01
NAME_02 = test_02
NAME_03 = test_03
NAME_04 = test_04
NAME_05 = test_05
NAME_06 = test_06

CC = clang
CFLAGS = -I $(HEADER) -Wall -Wextra -Werror -pthread

all: $(NAME_01) $(NAME_02) $(NAME_03) $(NAME_04) $(NAME_05) $(NAME_06)

$(NAME_01):
	@$(CC) $(CFLAGS) $(NAME_01).c -o $(NAME_01)

$(NAME_02):
	@$(CC) $(CFLAGS) $(NAME_02).c -o $(NAME_02)

$(NAME_03):
	@$(CC) $(CFLAGS) $(NAME_03).c -o $(NAME_03)

$(NAME_04):
	@$(CC) $(CFLAGS) $(NAME_04).c -o $(NAME_04)

$(NAME_05):
	@$(CC) $(CFLAGS) $(NAME_05).c -o $(NAME_05)

$(NAME_06):
	@$(CC) $(CFLAGS) $(NAME_06).c -o $(NAME_06)

clean: 
	@rm -f $(NAME_01).o $(NAME_02).o $(NAME_03).o $(NAME_04).o $(NAME_05).o $(NAME_06).o

fclean: clean
	@rm -f $(NAME_01) $(NAME_02) $(NAME_03) $(NAME_04) $(NAME_05) $(NAME_06)

re: fclean all

.PHONY: all clean fclean re
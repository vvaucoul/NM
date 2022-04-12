# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 21:04:48 by vvaucoul          #+#    #+#              #
#    Updated: 2022/04/12 15:41:41 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC				= clang
CFLAGS			= -I $(HEADER) -g3 -Wall -Wextra -Werror

### EXECUTABLE ###
NAME			= ft_nm
LIBFT			= 42_PCC_LIBFT.a

### INCLUDES ###
HEADER 			= ./includes/
SRC_PATH 		= srcs
OBJS_DIR		= objs

### SOURCES ###
SRCS			=	srcs/symbols/display_symbols_utils.c \
					srcs/symbols/display_symbols.c \
					srcs/x64/x64_meta_data.c \
					srcs/x64/x64_execution.c \
					srcs/parser.c \
					srcs/x32/x32_meta_data.c \
					srcs/x32/x32_execution.c \
					srcs/meta_files.c \
					srcs/main.c \
					srcs/execution.c \
					srcs/debug.c \
					srcs/utils.c \
					srcs/sort/symbol_sort.c


### OBJECTS ###
OBJS			=	$(SRCS:.c=.o)

### PRINT UTILS ###
PRINT_COMP		=	printf "\r$(_BOLD)$(_WHITE)- $(_BOLD)$(_YELLOW)[%s]\r\t\t\t\t\t $(_BOLD)$(_WHITE)[✓]\n$(_END)"

%.o : %.c
	@echo -n "\r                                                               "
	@$(PRINT_COMP) $@
	@$(CC) $(CFLAGS) -I. -c $< -o ${<:.c=.o}



################################################################################
#								 	 COLORS			  					   #
################################################################################

# This is a minimal set of ANSI/VT100 color codes
_END=$'\033[0m
_BOLD=$'\033[1m
_UNDER=$'\033[4m
_REV=$'\033[7m

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\033[40m
_IRED=$'\033[41m
_IGREEN=$'\033[42m
_IYELLOW=$'\033[43m
_IBLUE=$'\033[44m
_IPURPLE=$'\033[45m
_ICYAN=$'\033[46m
_IWHITE=$'\033[47m


### CLEAN ###
RM				= rm -f

### RULES ###

all:			$(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)
	@echo "\n\t$(_BOLD)$(_WHITE)- $(_GREEN)FT_NM COMPILED ! $(_BOLD)$(_WHITE)-$(NOC)"

$(LIBFT):
	@cd libft && make && cp $(LIBFT) ../.

clean:
	@cd libft && make clean
	@$(RM) -r $(OBJS)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

leaks:
	@echo "\n\t$(_BOLD)$(_WHITE)- $(_YELLOW)FT_NM CHECK LEAKS ! $(_BOLD)$(_WHITE)-$(NOC)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(NAME)

.PHONY: all clean fclean re leaks

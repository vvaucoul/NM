# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 18:52:08 by vvaucoul          #+#    #+#              #
#    Updated: 2022/04/11 13:29:41 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								 	 COLORS			  					 	   #
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

################################################################################
#								 	  PRINT		  					 	 	   #
################################################################################

### PRINT UTILS ###
PRINT_COMP		=	printf "\r$(_BOLD)$(_WHITE)- $(_BOLD)$(_CYAN)[%s]\r\t\t\t\t\t $(_BOLD)$(_WHITE)[✓]\n"


################################################################################
#								   COMPILATION		  					 	   #
################################################################################

NAME = 42_PCC_LIBFT.a
SRCS = 	srcs/convert/ft_itoa.c \
		srcs/convert/ft_atoi.c \
		srcs/convert/ft_itoa_base.c \
		srcs/array/ft_acol.c \
		srcs/array/ft_split.c \
		srcs/array/ft_alen.c \
		srcs/array/ft_acpy.c \
		srcs/array/ft_asize.c \
		srcs/array/ft_acof.c \
		srcs/string/ft_strsncmp.c \
		srcs/string/ft_multijoin.c \
		srcs/string/ft_scof.c \
		srcs/string/ft_lentc.c \
		srcs/string/ft_strchr.c \
		srcs/string/ft_substr.c \
		srcs/string/ft_strtolower.c \
		srcs/string/ft_strdup.c \
		srcs/string/ft_strrdbls.c \
		srcs/string/ft_strzap.c \
		srcs/string/ft_strmapi.c \
		srcs/string/ft_strjoin.c \
		srcs/string/ft_strcjoin.c \
		srcs/string/ft_strcmp.c \
		srcs/string/ft_strsplit.c \
		srcs/string/ft_strtrim.c \
		srcs/string/ft_strremove.c \
		srcs/string/ft_fstrcjoin.c \
		srcs/string/ft_sncof.c \
		srcs/string/ft_fstrjoin.c \
		srcs/string/ft_strrep.c \
		srcs/string/ft_strlen.c \
		srcs/string/ft_strcpy.c \
		srcs/string/ft_lents.c \
		srcs/string/ft_strncmp.c \
		srcs/string/ft_strncpy.c \
		srcs/memory/ft_memchr.c \
		srcs/memory/ft_memupper.c \
		srcs/memory/ft_memcpy.c \
		srcs/memory/ft_swap.c \
		srcs/memory/ft_memcrm.c \
		srcs/memory/ft_memalloc.c \
		srcs/memory/ft_memcmp.c \
		srcs/memory/ft_memmove.c \
		srcs/memory/ft_vswap.c \
		srcs/memory/ft_bzero.c \
		srcs/memory/ft_memscmp.c \
		srcs/memory/ft_memset.c \
		srcs/memory/ft_memsrm.c \
		srcs/memory/ft_memlower.c \
		srcs/memory/ft_memshr.c \
		srcs/number/ft_nbrlen.c \
		srcs/alloc/ft_aalloc.c \
		srcs/alloc/ft_afree.c \
		srcs/alloc/ft_realloc.c \
		srcs/alloc/ft_calloc.c \
		srcs/alloc/ft_multifree.c \
		srcs/alloc/ft_free.c \
		srcs/printf/ft_printf.c \
		srcs/linked_list/ft_lstadd_front.c \
		srcs/linked_list/ft_lstsize.c \
		srcs/linked_list/ft_lstdelone.c \
		srcs/linked_list/ft_lstclear.c \
		srcs/linked_list/ft_lstnew.c \
		srcs/linked_list/ft_lstlast.c \
		srcs/linked_list/ft_lstadd_back.c \
		srcs/linked_list/ft_lstiter.c \
		srcs/char/ft_isalpha.c \
		srcs/char/ft_isalnum.c \
		srcs/char/ft_isascii.c \
		srcs/char/ft_isspace.c \
		srcs/char/ft_tolower.c \
		srcs/char/ft_ccof.c \
		srcs/char/ft_isupper.c \
		srcs/char/ft_islower.c \
		srcs/char/ft_isdigit.c \
		srcs/char/ft_toupper.c \
		srcs/print/ft_pustr.c \
		srcs/print/ft_putchar.c \
		srcs/print/ft_putnbr.c \
		srcs/print/ft_putunbr.c \
		srcs/print/ft_putull.c \
		srcs/print/ft_putsarray.c \
		srcs/print/ft_putnbr_base.c \
		srcs/print/ft_putendl.c


CC = clang
AR = ar -rc
CFLAGS = -Wall -Wextra -g3 # -Werror # -
OBJS = $(SRCS:.c=.o)

%.o:%.c
	@echo -n "\r                                                               "
	@$(PRINT_COMP) $@
	@$(CC) $(CFLAGS) -I./includes -c $< -o ${<:.c=.o}

################################################################################
#								   	  RULES			  					 	   #
################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

test:
	make
	@$(PRINT_COMP) "lft_test"
	@clang tests/main.c  -I./includes 42_PCC_LIBFT.a -o lft_test

.PHONY: all clean fclean re test
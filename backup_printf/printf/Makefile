# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 19:24:12 by gjeon             #+#    #+#              #
#    Updated: 2021/02/16 19:40:26 by gjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

FILES		= ft_printf format_type1 format_type2 printf_utils1\
			  printf_utils2 set_flags

OBJS		= $(SRCS:.c=.o)
INCS		= .

RM			= rm -f
AR			= ar rcs
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix ./, $(addsuffix .o, $(FILES)))

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $^

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

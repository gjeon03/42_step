# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 19:24:12 by gjeon             #+#    #+#              #
#    Updated: 2021/02/23 16:26:57 by gjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

FILES		= ft_printf ft_format_type1 ft_format_type2 ft_printf_utils ft_printf_utils_itoa ft_set_flags

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

bonus : all

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 12:50:14 by syamashi          #+#    #+#              #
#    Updated: 2020/07/27 23:25:15 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS = addsymbol.c\
	   convert_num.c\
	   convert_uxp.c\
	   deci.c\
	   deci_check_and_conv.c\
	   deci_dans.c\
	   deci_ians_nanflag.c\
	   deci_round.c\
	   deci_saf.c\
	   ft_printf.c\
	   getflags.c\
	   putout_left_right.c\
	   putout_zero.c\
	   unicode.c\
	   util1.c\

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc

$(NAME):$(OBJS)
	$(MAKE) all -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) -c $(HEADER) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus

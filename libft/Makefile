# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 17:30:02 by gjeon             #+#    #+#              #
#    Updated: 2020/12/31 17:09:28 by gjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_memset ft_bzero ft_memcpy ft_strlen ft_strlcpy ft_strlcat ft_strncmp \
	   ft_atoi ft_isalpha ft_isalnum ft_isascii

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix ./, $(addsuffix .o, $(FILES)))

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

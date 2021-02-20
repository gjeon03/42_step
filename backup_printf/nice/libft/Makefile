# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 21:04:46 by syamashi          #+#    #+#              #
#    Updated: 2020/07/21 00:31:31 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c\
	   ft_bzero.c\
	   ft_calloc.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_itoa.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_putchar_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_putstr_fd.c\
	   ft_split.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strdup.c\
	   ft_strjoin.c\
	   ft_strlcpy.c\
	   ft_strlen.c\
	   ft_strmapi.c\
	   ft_strncmp.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strtrim.c\
	   ft_substr.c\
	   ft_tolower.c\
	   ft_toupper.c

BONUSES = ft_lstadd_back_bonus.c\
		  ft_lstadd_front_bonus.c\
		  ft_lstclear_bonus.c\
		  ft_lstdelone_bonus.c\
		  ft_lstiter_bonus.c\
		  ft_lstlast_bonus.c\
		  ft_lstmap_bonus.c\
		  ft_lstnew_bonus.c\
		  ft_lstsize_bonus.c

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUSES:%.c=%.o)
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(BOBJS)
	ar -rc $(NAME) $(BOBJS)

.PHONY: all clean fclean re bonus

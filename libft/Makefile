# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 17:30:02 by gjeon             #+#    #+#              #
#    Updated: 2021/01/16 22:48:16 by gjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp \
		ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr ft_isprint ft_tolower \
		ft_strncmp ft_strnstr ft_isdigit ft_toupper ft_atoi ft_isalpha ft_isalnum \
		ft_isascii ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split \
		ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \

FILES_B = ft_lstnew ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
		  ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

CC = gcc
RM = rm -f
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix ./, $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix ./, $(addsuffix .c, $(FILES_B)))

OBJS = $(addprefix ./, $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix ./, $(addsuffix .o, $(FILES_B)))

all: $(NAME)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $(NAME) $^

bonus : $(OBJS) $(OBJS_B)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

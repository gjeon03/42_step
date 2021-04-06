NAME			= cub3D
LIBFT			= libft
LIBFT_LIB		= libft.a

SRCS			= ./step1.c

OBJS			= ${SRCS:.c=.o}

INCLUDE			= cub3d.h

RM				= rm -f
CC				= gcc

CFLAGS			= -Wall -Wextra -Werror
MLXFLAGS		= -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
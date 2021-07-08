NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= push_swap.c set_pivot.c stack_action1.c\
			stack_action2.c stack_sort.c stack_utile1.c\
			stack_utile2.c error.c

RM			= rm -f
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)

all : $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB) :
	make all -C $(LIBFT)

$(NAME) : $(LIBFT)/$(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
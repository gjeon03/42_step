SERVER		= server
CLIENT		= client
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= server.c error.c client.c

RM			= rm -f
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)

$(SERVER) : $(OBJS)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) error.o server.o -o $(SERVER)
	$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) client.o -o $(CLIENT)

all : $(SERVER)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT)

re : fclean all
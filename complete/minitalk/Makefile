SERVER		= server
CLIENT		= client
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= server.c error.c client.c

RM			= rm -f
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)

all : $(LIBFT_LIB) $(SERVER) $(CLIENT)

$(LIBFT_LIB) :
	@make all -C $(LIBFT)

$(SERVER) : $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) error.o server.o -o $@
	@printf "\e[38;5;46m$@ successfully build\e[0m\n"

$(CLIENT) : $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT)/$(LIBFT_LIB) error.o client.o -o $@
	@printf "\e[38;5;46m$@ successfully build\e[0m\n"

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)
	make fclean -C $(LIBFT)

re : fclean all
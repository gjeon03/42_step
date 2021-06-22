NAME		= cub3D
LIBFT		= utiles/libft
MLX			= mlx
LIBFT_LIB	= libft.a

SRCS		= main.c \
				config/config_resolution.c \
				map/map.c \
				map/parse_map.c \
				map/parse_map2.c \
				srcs/draw.c \
				srcs/key_update.c \
				srcs/print_error.c \
				srcs/raycast2.c \
				srcs/sprite2.c \
				srcs/texture.c \
				srcs/key.c \
				srcs/key_update2.c \
				srcs/raycast.c \
				srcs/sprite.c \
				srcs/sprite_utile.c \
				srcs/utile.c \
				utiles/get_next_line/get_next_line.c

RM			= rm -f
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJS		= $(SRCS:.c=.o) 

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	make all -C mlx
	$(CC) $(CFLAGS) $(MLXFLAGS) $(LIBFT)/$(LIBFT_LIB) -o $(NAME) $^

all : $(NAME)

bonus : all

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	make clean -C $(MLX)

re : fclean all
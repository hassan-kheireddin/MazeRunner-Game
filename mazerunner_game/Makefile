CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = so_long

# Source files
SRCS = \
	src/check_map1.c \
	src/check_map2.c \
	src/check_path.c \
	src/free.c \
	src/get_map.c \
	src/init_game.c \
	src/init_mlx.c \
	src/loop.c \
	src/player.c \
	src/render_map.c \
	src/trim.c\
	src/main.c

# Object files
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

run: all clean

.SILENT:
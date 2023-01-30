CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = fractol
SRC = main.c mandelbrot.c color.c window.c exit_window.c
OBJ = $(SRC:.c=.o)


MLX_DIR = mlx_linux
MLX_BINARY = libmlx_Linux.a
FTPRINTF_BINARY = libftprintf.a
LIBFT_BINARY = libft.a

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -O3 -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $^ $(MLX_BINARY) $(FTPRINTF_BINARY) $(LIBFT_BINARY) -lXext -lX11 -lm -lz -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
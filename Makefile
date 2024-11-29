SRCS_PATH = ./src/

SRCS_FILE = 	$(SRCS_PATH)/fractol.c \
				$(SRCS_PATH)/fractal/mandelbrot.c \
				$(SRCS_PATH)/utils/color.c \
				$(SRCS_PATH)/utils/complex.c

OBJECT_FILE = 	$(SRCS_FILE:.c=.o)

CC = cc

DEBUG = 	-g3 #-fsanitize=address

CFLAGS = 	-Wall -Wextra -Werror $(DEBUG)

LIBFT = 	libft.a

MLX_INCLUDE = -I/usr/include -Imlx_linux
MLX_FLAG = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LIB =./mlx_linux/libmlx_Linux.a

NAME = 		fractol

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C libft bonus
	mv libft/$(LIBFT) ./$(LIBFT)

$(MLX_LIB):
	make -C mlx_linux all

$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX_LIB) $(OBJECT_FILE)
		$(CC) $(CFLAGS) $(MLX_FLAG) -o $(NAME) $(OBJECT_FILE) $(LIBFT) $(MLX_LIB)

clean:
	rm -f $(OBJECT_FILE) $(LIBFT) $(FT_PRINTF)
	make -C libft clean
	make -C mlx_linux clean

fclean: clean
	rm -f $(NAME) $(LIBFT) $(FT_PRINTF)

re: fclean $(NAME)

run: all
	./$(NAME)

.PHONY: all re fclean clean
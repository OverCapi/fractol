SRCS_PATH = ./src
SRCS_FRACTAL_PATH = $(SRCS_PATH)/fractal
SRCS_UTILS_PATH = $(SRCS_PATH)/utils
SRCS_EVENT_PATH = $(SRCS_PATH)/event

SRCS_UTILS = 	$(SRCS_UTILS_PATH)/color.c \
				$(SRCS_UTILS_PATH)/complex.c \
				$(SRCS_UTILS_PATH)/image.c \
				$(SRCS_UTILS_PATH)/ft_atod.c \
				$(SRCS_UTILS_PATH)/exit_fractal.c \
				$(SRCS_UTILS_PATH)/modif_julia_set.c \

SRCS_EVENT = 	$(SRCS_EVENT_PATH)/key_event.c \
				$(SRCS_EVENT_PATH)/mouse_event.c

SRCS_FRACTAL = 	$(SRCS_FRACTAL_PATH)/mandelbrot.c \
				$(SRCS_FRACTAL_PATH)/julia.c \
				$(SRCS_FRACTAL_PATH)/burning_ship.c \

SRCS_FRACTOL = 	$(SRCS_PATH)/fractol.c \
				$(SRCS_PATH)/update.c \
				$(SRCS_PATH)/parsing.c \
				$(SRCS_PATH)/init.c

SRCS_FILE =		$(SRCS_FRACTOL) \
				$(SRCS_FRACTAL) \
				$(SRCS_UTILS) \
				$(SRCS_EVENT)

OBJECT_FILE = 	$(SRCS_FILE:.c=.o)

CC = cc

DEBUG = 	#-g3 -fsanitize=address

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
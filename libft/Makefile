CHAR_PATH = ./char
MEM_PATH = ./mem
CONVERTER_PATH = ./converter
STR_PATH = ./str
WRITE_PATH = ./write
LINKED_LIST_PATH = ./linked_list
FT_PRINTF = ./ft_printf
GNL_PATH = ./gnl
EXIT_PATH = ./exit

SRCS_CHAR_FUNCTION =			$(CHAR_PATH)/ft_iswhite_space.c \
								$(CHAR_PATH)/ft_isalnum.c \
								$(CHAR_PATH)/ft_isalpha.c \
								$(CHAR_PATH)/ft_isascii.c \
								$(CHAR_PATH)/ft_isdigit.c \
								$(CHAR_PATH)/ft_isprint.c \
								$(CHAR_PATH)/ft_tolower.c \
								$(CHAR_PATH)/ft_toupper.c	

SRCS_MEM_FUNCTION =				$(MEM_PATH)/ft_bzero.c \
								$(MEM_PATH)/ft_calloc.c \
								$(MEM_PATH)/ft_memchr.c \
								$(MEM_PATH)/ft_memcmp.c \
								$(MEM_PATH)/ft_memcpy.c \
								$(MEM_PATH)/ft_memmove.c \
								$(MEM_PATH)/ft_memset.c

SRCS_STR_FUNCTION = 			$(STR_PATH)/ft_split.c \
								$(STR_PATH)/ft_strchr.c \
								$(STR_PATH)/ft_strdup.c \
								$(STR_PATH)/ft_striteri.c \
								$(STR_PATH)/ft_strjoin.c \
								$(STR_PATH)/ft_strlcat.c \
								$(STR_PATH)/ft_strlcpy.c \
								$(STR_PATH)/ft_strlen.c \
								$(STR_PATH)/ft_strmapi.c \
								$(STR_PATH)/ft_strncmp.c \
								$(STR_PATH)/ft_strnstr.c \
								$(STR_PATH)/ft_strrchr.c \
								$(STR_PATH)/ft_strtrim.c \
								$(STR_PATH)/ft_substr.c

SRCS_CONVERTER_FUNCTION =		$(CONVERTER_PATH)/ft_atoi_safe.c \
								$(CONVERTER_PATH)/ft_atoi.c \
								$(CONVERTER_PATH)/ft_itoa.c

SRCS_WRITE_FUNCTION = 			$(WRITE_PATH)/ft_putchar_fd.c \
								$(WRITE_PATH)/ft_putendl_fd.c \
								$(WRITE_PATH)/ft_putnbr_fd.c \
								$(WRITE_PATH)/ft_putstr_fd.c

SRCS_LINKED_LIST_FUNCTION =		$(LINKED_LIST_PATH)/ft_lstnew_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstadd_front_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstsize_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstlast_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstadd_back_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstdelone_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstclear_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstiter_bonus.c \
								$(LINKED_LIST_PATH)/ft_lstmap_bonus.c

SRCS_FT_PRINTF = 				$(FT_PRINTF)/converter.c \
								$(FT_PRINTF)/converter_utils.c \
								$(FT_PRINTF)/ft_printf.c

SRCS_GNL_FUNCTION =				$(GNL_PATH)/get_next_line_bonus.c \
								$(GNL_PATH)/get_next_line_utils_bonus.c

SRCS_EXIT_FUNCTION =			$(EXIT_PATH)/exit_error.c

SRCS_FILE =						$(SRCS_CHAR_FUNCTION) \
								$(SRCS_MEM_FUNCTION) \
								$(SRCS_STR_FUNCTION) \
								$(SRCS_CONVERTER_FUNCTION) \
								$(SRCS_WRITE_FUNCTION) \
								$(SRCS_FT_PRINTF) \
								$(SRCS_GNL_FUNCTION) \
								$(SRCS_EXIT_FUNCTION)

OBJECT_FILE = $(SRCS_FILE:.c=.o)

OBJECT_FILE_BONUS = $(SRCS_LINKED_LIST_FUNCTION:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

NAME = libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECT_FILE)
		$(AR) $(NAME) $(OBJECT_FILE)

bonus: $(OBJECT_FILE) $(OBJECT_FILE_BONUS)
		$(AR) $(NAME) $(OBJECT_FILE) $(OBJECT_FILE_BONUS)

clean:
	rm -f $(OBJECT_FILE) $(OBJECT_FILE_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re

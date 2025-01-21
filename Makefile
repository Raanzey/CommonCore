NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SOURCES = push_swap.c push_swap_utils.c
OBJECTS = $(SOURCES:.c=.o)

# Libft Kütüphanesi
LIBFT_DIR = ../Push_swap/libft
LIBFT = $(LIBFT_DIR)/libft.a

# Default Rule
all: $(LIBFT) $(NAME)

# push_swap'in derlenmesi
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Libft'in derlenmesi
$(LIBFT):
	make -C $(LIBFT_DIR)

# Temizleme işlemleri
clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
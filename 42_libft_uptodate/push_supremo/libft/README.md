 cc -Wall -Wextra -Werror -Iincludes main.c libft.a



NAME = libft (nome qui) .a
LIBFT = libft.a
LIBFT_DIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

SRC = *************
OBJS = $(SRC:.c=.o)
LIBFT_OBJS = $(wildcard $(LIBFT_DIR)/*.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) 
	mv libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iincludes

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



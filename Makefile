NAME = push_swap

SRCS = main.c \

LIBFT = ./libft/libft.a 

LIBDIR = ./libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) -I$(LIBDIR) $(SRCS) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re

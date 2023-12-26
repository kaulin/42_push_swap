NAME = push_swap

SRCS = main.c \
	push_swap.c \
	#ps_push.c \
	ps_rotate.c \
	ps_rrotate.c \
	ps_swap.c \

LIBFT = ./libft/libft.a 

LIBDIR = ./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) -I$(LIBDIR) $(SRCS) $(LIBFT) -o $@

db: $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) -I$(LIBDIR) $(SRCS) $(LIBFT) -o $(NAME) -g
	make clean

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re db

NAME = push_swap

SRCS = main.c \
	push_swap.c \
	ps_moves.c \
	ps_smart_move.c \
	ps_sort.c \
	ps_sort_utils.c \
	ps_utils.c \

DL_SRCS = dlist_utils.c \
	dlist_moves.c \

DL_OBJ = $(DL_SRCS:.c=.o)

DLIST = dlist.a

LIBFT = libft.a 

LIBDIR = ./libft/

LIBPATH = $(LIBDIR)$(LIBFT)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBPATH) $(DLIST) $(SRCS)
	$(CC) $(CFLAGS) -I$(LIBDIR) $(SRCS) $(LIBPATH) $(DLIST) -o $(NAME)

db: $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) -I$(LIBDIR) $(SRCS) $(LIBPATH) $(DLIST) -o $(NAME) -g
	make clean

$(LIBPATH): $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

$(DLIST): $(DL_OBJ)
	ar -crs $(DLIST) $(DL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(DL_OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(DLIST)
	make fclean -C $(LIBDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re db dlist

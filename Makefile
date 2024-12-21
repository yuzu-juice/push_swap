NAME		= push_swap
OPERATIONS	= ops
SRCS		= push_swap.c \
			ft_qsort.c \
			sort_utils.c \
			get_index.c \
			input_validation.c \
			$(OPERATIONS)/swap.c \
			$(OPERATIONS)/push.c \
			$(OPERATIONS)/rotate.c \
			$(OPERATIONS)/reverse_rotate.c

OBJS	= $(SRCS:.c=.o)
HEADERS	= push_swap.h
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	cd "$(PWD)/Libft" && make && cd ..
	$(CC) $(CFLAG) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADERS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cd "$(PWD)/Libft" && make clean && cd ..
	rm -f $(OBJS)

fclean: clean
	cd "$(PWD)/Libft" && make fclean && cd ..
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

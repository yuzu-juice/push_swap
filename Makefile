NAME		= push_swap
OPERATIONS	= ops
UTILS		= utils
SRCS		= push_swap.c \
			$(UTILS)/qsort.c \
			$(UTILS)/get_index.c \
			$(UTILS)/get_pivot.c \
			$(UTILS)/split_by_pivot.c \
			$(UTILS)/input_validation.c \
			$(UTILS)/is_sorted.c \
			$(UTILS)/stack_a/sort_a_lte_four.c \
			$(UTILS)/stack_a/sort_a.c \
			$(UTILS)/stack_b/sort_b_lte_four.c \
			$(UTILS)/stack_b/sort_b.c \
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADERS)

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

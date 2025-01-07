NAME		= push_swap
LIB_NAME	= $(NAME).a
FEATS		= features
OPS			= operations
UTILS		= utils
SRCS		= push_swap.c \
			$(FEATS)/validate_input.c \
			$(FEATS)/init_stack.c \
			$(FEATS)/sort_stack.c \
			$(FEATS)/stack_a/sort_a.c \
			$(FEATS)/stack_a/sort_a_lte_four.c \
			$(FEATS)/stack_a/sort_a_two.c \
			$(FEATS)/stack_a/sort_a_three.c \
			$(FEATS)/stack_a/sort_a_four.c \
			$(FEATS)/stack_b/sort_b.c \
			$(FEATS)/stack_b/sort_b_lte_three.c \
			$(FEATS)/print_ops.c \
			$(FEATS)/finalize.c \
			$(FEATS)/brute_force_search.c \
			$(FEATS)/operations/init_ops.c \
			$(FEATS)/operations/append_node.c \
			$(FEATS)/operations/optimize.c \
			$(FEATS)/operations/optimize1.c \
			$(FEATS)/operations/optimize2.c \
			$(FEATS)/operations/optimize3.c \
			$(FEATS)/operations/optimize4.c \
			$(FEATS)/operations/optimize5.c \
			$(FEATS)/operations/optimize6.c \
			$(FEATS)/operations/optimize7.c \
			$(UTILS)/get_pivot.c \
			$(UTILS)/is_sorted.c \
			$(UTILS)/split_by_pivot.c \
			$(UTILS)/get_index.c \
			$(OPS)/swap.c \
			$(OPS)/push.c \
			$(OPS)/rotate.c \
			$(OPS)/reverse_rotate.c \
			$(OPS)/apply_n_times.c \
			$(OPS)/rotate_optimally.c

OBJS	= $(SRCS:.c=.o)
HEADERS	= push_swap.h
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
LIBFT = Libft/libft.a

all: $(NAME)

lib: $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)
	ranlib $(LIB_NAME)

$(NAME): $(OBJS)
	cd "$(PWD)/Libft" && make && cd ..
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -I $(HEADERS)

%.o: %.c $(HEADERS)
	# $(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cd "$(PWD)/Libft" && make clean && cd ..
	rm -f $(OBJS)
	rm -f $(LIB_NAME)

fclean: clean
	cd "$(PWD)/Libft" && make fclean && cd ..
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#include "../push_swap.h"

static void	print_stack(t_stack stack)
{
	size_t	i;

	i = 0;
	while ((int)i < stack.top + 1)
	{
		ft_printf("%d ", stack.stack[i]);
		i++;
	}
	ft_printf("\n");
}

static _Bool is_invalid_sequence(t_ops current, t_ops prev)
{
	// 同じスタックに対する同じ操作の連続を防ぐ
	if (current == SA && prev == SA)
		return (true);
	if (current == SB && prev == SB)
		return (true);
	if (current == SS && prev == SS)
		return (true);

	// 相殺される操作の組み合わせを防ぐ
	if ((current == PA && prev == PB) || (current == PB && prev == PA))
		return (true);
	if ((current == RA && prev == RRA) || (current == RRA && prev == RA))
		return (true);
	if ((current == RB && prev == RRB) || (current == RRB && prev == RB))
		return (true);

	// 非効率な操作の組み合わせを防ぐ
	if ((current == RB && prev == RA) || (current == RA && prev == RB))
		return (true);
	if ((current == RRB && prev == RRA) || (current == RRA && prev == RRB))
		return (true);
	if ((current == SB && prev == SA) || (current == SA && prev == SB))
		return (true);

    // スタックBが空の時の無意味な操作を防ぐ
    if (current == SB || current == RB || current == RRB)
        return (true);

	return (false);
}

static void	generate_next_ops_list(t_list *ops)
{
	t_list	*last_node;
	t_list	*new_node;
	t_list	*tmp;
	_Bool	is_invalid;

	last_node = get_last_node(ops);
	is_invalid = true;
	while (is_invalid)
	{
		last_node->value++;
		if (last_node->value > RRR)
		{
			tmp = last_node;
			while (tmp)
			{
				if (tmp->value >= RRR)
				{
					tmp->value = SA;
					tmp = tmp->prev;
				}
				else
				{
					tmp->value++;
					break;
				}
			}
			if (!tmp)
			{
				new_node = malloc(sizeof(t_list));
				new_node->value = SA;
				new_node->next = NULL;
				new_node->prev = last_node;
				last_node->next = new_node;
				return;
			}
		}
		if (!last_node->prev || !is_invalid_sequence(last_node->value, last_node->prev->value))
			is_invalid = false;
	}
}

static _Bool	do_op(t_stacks *stacks, t_ops op)
{
	if (op == SA)
		return (sa(stacks, NULL));
	if (op == SB)
		return (sb(stacks, NULL));
	if (op == SS)
		return (ss(stacks, NULL));
	if (op == PA)
		return (pa(stacks, NULL));
	if (op == PB)
		return (pb(stacks, NULL));
	if (op == RA)
		return (ra(stacks, NULL));
	if (op == RB)
		return (rb(stacks, NULL));
	if (op == RR)
		return (rr(stacks, NULL));
	if (op == RRA)
		return (rra(stacks, NULL));
	if (op == RRB)
		return (rrb(stacks, NULL));
	if (op == RRR)
		return (rrr(stacks, NULL));
	return (false);
}

static _Bool	do_ops(t_stacks *stacks, t_list *ops)
{
	t_list	*node;
	_Bool	status;
	node = ops;
	while (node)
	{
		status = do_op(stacks, node->value);
		if (!status)
			return (false);
		node = node->next;
	}
	return (true);
}

static void	copy_stacks(t_stacks src, t_stacks *dst)
{
	size_t	size;

	size = src.a.top + 1;
	dst->a.top = src.a.top;
	dst->a.bottom = src.a.bottom;
	dst->b.top = src.b.top;
	dst->b.bottom = src.b.bottom;
	ft_memcpy(dst->a.stack, src.a.stack, sizeof(int) * size);
	ft_memcpy(dst->b.stack, src.b.stack, sizeof(int) * size);
}

static _Bool	all_in_range(t_stack *stack, size_t start, size_t end)
{
	size_t	i;

	i = stack->bottom;
	while ((int)i < stack->top + 1)
	{
		if (stack->stack[i] < (int)start || stack->stack[i] > (int)end)
			return (false);
		i++;
	}
	return (true);
}


t_list	*brute_force_search(t_stacks stacks, size_t size)
{
	t_list		*shortest_ops;
	t_stacks	stacks_copy;
	size_t		stack_size;

	shortest_ops = malloc(sizeof(t_list));
	if (!shortest_ops)
		return (NULL);
	init_ops(shortest_ops);
	shortest_ops->value = SA;
	stack_size = stacks.a.top + 1;
	stacks_copy.a.stack = malloc(sizeof(int) * stack_size);
	if (!stacks_copy.a.stack)
	{
		free_ops(shortest_ops);
		return (NULL);
	}
	stacks_copy.b.stack = malloc(sizeof(int) * stack_size);
	if (!stacks_copy.b.stack)
	{
		free(stacks_copy.a.stack);
		free_ops(shortest_ops);
		return (NULL);
	}

	while (true)
	{
		copy_stacks(stacks, &stacks_copy);
		ft_printf("before do_ops\n");
		print_stack(stacks_copy.a);
		print_ops(shortest_ops);
		if (!do_ops(&stacks_copy, shortest_ops))
		{
			generate_next_ops_list(shortest_ops);
			continue ;
		}
		ft_printf("after do_ops\n");
		ft_printf("stacks_copy.a.top - stacks_copy.a.bottom + 1: %u, size: %u\n", stacks_copy.a.top - stacks_copy.a.bottom + 1, size);
		print_stack(stacks_copy.a);
		if (stacks_copy.a.top + 1 == (int)size && all_in_range(&stacks_copy.a, 0, size - 1) && is_sorted(&stacks_copy.a, true))
		{
			free(stacks_copy.a.stack);
			free(stacks_copy.b.stack);
			return (shortest_ops);
		}
		generate_next_ops_list(shortest_ops);
	}
	free(stacks_copy.a.stack);
	free(stacks_copy.b.stack);
	return (NULL);
}

// int	main(void)
// {
// 	t_stacks	stacks;
// 	t_list		*shortest_ops;
// 	int			*stack_a;
// 	int			*stack_b;

// 	// スタックのメモリ確保
// 	stack_a = (int *)malloc(sizeof(int) * 6);
// 	if (!stack_a)
// 		return (1);
// 	stack_b = (int *)malloc(sizeof(int) * 6);
// 	if (!stack_b)
// 	{
// 		free(stack_a);
// 		return (1);
// 	}

// 	// スタックの初期化
// 	stack_a[0] = 100;
// 	stack_a[1] = 99;
// 	stack_a[2] = 2;
// 	stack_a[3] = 1;
// 	stack_a[4] = 4;
// 	stack_a[5] = 3;
// 	stack_b[0] = 0;
// 	stack_b[1] = 0;
// 	stack_b[2] = 0;
// 	stack_b[3] = 0;
// 	stack_b[4] = 0;
// 	stack_b[5] = 0;

// 	stacks.a = (t_stack){stack_a, 5, 2};
// 	stacks.b = (t_stack){stack_b, -1, 0};
// 	shortest_ops = brute_force_search(stacks, stacks.a.top + 1);
// 	ft_printf("=====FOUND=====\n");
// 	print_ops(shortest_ops);
// 	free_ops(shortest_ops);
// 	free(stack_a);
// 	free(stack_b);
// 	return (0);
// }

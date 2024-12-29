#include "../push_swap.h"

void	append_node(t_list *ops, t_ops op)
{
	t_list	*op_node;
	t_list	*current;

	current = ops;
	op_node = malloc(sizeof(t_list));
	op_node->value = op;
	op_node->next = NULL;
	while (current->next)
		current = current->next;
	current->next = op_node;
}

void	optimize_list(t_list *ops)
{
    t_list	*tmp1;
	t_list	*tmp2;

    while (ops)
    {
		if (ops->next && ops->next->next)
		{
			if ((ops->next->value == SA && ops->next->next->value == SA) ||
				(ops->next->value == SB && ops->next->next->value == SB) ||
				(ops->next->value == PA && ops->next->next->value == PB) ||
				(ops->next->value == PB && ops->next->next->value == PA) ||
				(ops->next->value == RA && ops->next->next->value == RRA) ||
				(ops->next->value == RB && ops->next->next->value == RRB) ||
				(ops->next->value == RRA && ops->next->next->value == RA) ||
				(ops->next->value == RRB && ops->next->next->value == RB))
			{
				tmp1 = ops->next;
				tmp2 = ops->next->next;
				ops->next = ops->next->next->next;
				free(tmp1);
				free(tmp2);
				continue;
			}
			if ((ops->next->value == SA && ops->next->next->value == SB) ||
				(ops->next->value == SB && ops->next->next->value == SA))
			{
				tmp1 = ops->next;
				tmp2 = ops->next->next;
				ops->next->value = SS;
				ops->next = ops->next->next->next;
				free(tmp1);
				free(tmp2);
			}
			if  ((ops->next->value == RA && ops->next->next->value == RB) ||
				(ops->next->value == RB && ops->next->next->value == RA))
			{
				tmp1 = ops->next;
				tmp2 = ops->next->next;
				ops->next->value = RR;
				ops->next = ops->next->next->next;
				free(tmp1);
				free(tmp2);
			}
			if ((ops->next->value == RRA && ops->next->next->value == RRB) ||
				(ops->next->value == RRB && ops->next->next->value == RRA))
			{
				tmp1 = ops->next;
				tmp2 = ops->next->next;
				ops->next->value = RRR;
				ops->next = ops->next->next->next;
				free(tmp1);
				free(tmp2);
			}
		}
        ops = ops->next;
    }
}

void	print_list(t_list *ops)
{
	while (ops)
	{
		if (ops->value == SA)
			ft_printf("sa\n");
		else if (ops->value == SB)
			ft_printf("sb\n");
		else if (ops->value == SS)
			ft_printf("ss\n");
		else if (ops->value == PA)
			ft_printf("pa\n");
		else if (ops->value == PB)
			ft_printf("pb\n");
		else if (ops->value == RA)
			ft_printf("ra\n");
		else if (ops->value == RB)
			ft_printf("rb\n");
		else if (ops->value == RR)
			ft_printf("rr\n");
		else if (ops->value == RRA)
			ft_printf("rra\n");
		else if (ops->value == RRB)
			ft_printf("rrb\n");
		else if (ops->value == RRR)
			ft_printf("rrr\n");
		ops = ops->next;
	}
}

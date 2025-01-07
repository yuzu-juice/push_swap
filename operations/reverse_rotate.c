/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:52 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:22:35 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	handle_rra(t_stack *a)
{
	int	tmp;
	int	i;

	tmp = a->stack[0];
	i = 0;
	while (i < a->top)
	{
		a->stack[i] = a->stack[i + 1];
		i++;
	}
	a->stack[a->top] = tmp;
}

static void	handle_rrb(t_stack *b)
{
	int	tmp;
	int	i;

	tmp = b->stack[0];
	i = 0;
	while (i < b->top)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->stack[b->top] = tmp;
}

_Bool	rra(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;

	a = &stacks->a;
	if (a->top - a->bottom <= 0)
		return (false);
	handle_rra(a);
	if (ops)
		append_node(stacks, ops, RRA);
	return (true);
}

_Bool	rrb(t_stacks *stacks, t_list *ops)
{
	t_stack	*b;

	b = &stacks->b;
	if (b->top - b->bottom <= 0)
		return (false);
	handle_rrb(b);
	if (ops)
		append_node(stacks, ops, RRB);
	return (true);
}

_Bool	rrr(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	if (a->top - a->bottom <= 0 && b->top - b->bottom <= 0)
		return (false);
	handle_rra(a);
	handle_rrb(b);
	if (ops)
		append_node(stacks, ops, RRR);
	return (true);
}

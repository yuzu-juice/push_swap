/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:42 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:20:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	handle_ra(t_stack *a)
{
	int	tmp;
	int	i;

	tmp = a->stack[a->top];
	i = a->top;
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = tmp;
}

static void	handle_rb(t_stack *b)
{
	int	tmp;
	int	i;

	tmp = b->stack[b->top];
	i = b->top;
	while (i > 0)
	{
		b->stack[i] = b->stack[i - 1];
		i--;
	}
	b->stack[0] = tmp;
}

void	ra(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;

	a = &stacks->a;
	if (a->top == 0)
		return ;
	handle_ra(a);
	if (ops)
		append_node(stacks, ops, RA);
}

void	rb(t_stacks *stacks, t_list *ops)
{
	t_stack	*b;

	b = &stacks->b;
	if (b->top == 0)
		return ;
	handle_rb(b);
	if (ops)
		append_node(stacks, ops, RB);
}

void	rr(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	if (a->top == 0 && b->top == 0)
		return ;
	if (a->top == 0)
	{
		rb(stacks, ops);
		return ;
	}
	if (b->top == 0)
	{
		ra(stacks, ops);
		return ;
	}
	handle_ra(a);
	handle_rb(b);
	if (ops)
		append_node(stacks, ops, RR);
}

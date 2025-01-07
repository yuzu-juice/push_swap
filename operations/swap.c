/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:49:40 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:39:51 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	handle_sa(t_stack *a)
{
	int	tmp;

	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = tmp;
}

static void	handle_sb(t_stack *b)
{
	int	tmp;

	tmp = b->stack[b->top];
	b->stack[b->top] = b->stack[b->top - 1];
	b->stack[b->top - 1] = tmp;
}

_Bool	sa(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;

	a = &stacks->a;
	if (a->top - a->bottom <= 1)
		return (false);
	handle_sa(a);
	if (ops)
		append_node(stacks, ops, SA);
	return (true);
}

_Bool	sb(t_stacks *stacks, t_list *ops)
{
	t_stack	*b;

	b = &stacks->b;
	if (b->top - b->bottom <= 1)
	{
		ft_printf("sb: stack b is too small\n");
		return (false);
	}
	handle_sb(b);
	if (ops)
		append_node(stacks, ops, SB);
	return (true);
}

_Bool	ss(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	if (a->top - a->bottom <= 1 || b->top - b->bottom <= 1)
		return (false);
	handle_sa(a);
	handle_sb(b);
	if (ops)
		append_node(stacks, ops, SS);
	return (true);
}

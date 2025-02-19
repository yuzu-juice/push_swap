/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:38 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 21:26:05 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	if (b->top == -1)
		return ;
	(a->top)++;
	a->stack[a->top] = b->stack[b->top];
	(b->top)--;
	if (ops)
		append_node(stacks, ops, PA);
}

void	pb(t_stacks *stacks, t_list *ops)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	if (a->top == -1)
		return ;
	(b->top)++;
	b->stack[b->top] = a->stack[a->top];
	(a->top)--;
	if (ops)
		append_node(stacks, ops, PB);
}

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

void	sa(t_stack *a, t_list *ops)
{
	if (a->top < 1)
		return ;
	handle_sa(a);
	append_node(ops, SA);
}

void	sb(t_stack *b, t_list *ops)
{
	if (b->top < 1)
		return ;
	handle_sb(b);
	append_node(ops, SB);
}

void	ss(t_stack *a, t_stack *b, t_list *ops)
{
	if (a->top < 1 && b->top < 1)
		return ;
	if (a->top < 1)
		sa(a, ops);
	if (b->top < 1)
		sb(b, ops);
	handle_sa(a);
	handle_sb(b);
	append_node(ops, SS);
}

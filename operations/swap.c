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

void	sa(t_stack *a, t_list *ops)
{
	int	tmp;

	if (a->top < 1)
	{
		append_node(ops, SA);
		return ;
	}
	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = tmp;
	append_node(ops, SA);
}

void	sb(t_stack *b, t_list *ops)
{
	int	tmp;

	if (b->top < 1)
	{
		append_node(ops, SB);
		return ;
	}
	tmp = b->stack[b->top];
	b->stack[b->top] = b->stack[b->top - 1];
	b->stack[b->top - 1] = tmp;
	append_node(ops, SB);
}

void	ss(t_stack *a, t_stack *b, t_list *ops)
{
	sa(a, ops);
	sb(b, ops);
}

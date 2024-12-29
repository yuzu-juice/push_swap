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

void	sa(t_stack *stack, t_list *ops)
{
	int	tmp;
	if (stack->top < 1)
	{
		append_node(ops, SA);
		return ;
	}
	tmp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = tmp;

	append_node(ops, SA);
}

void	sb(t_stack *stack, t_list *ops)
{
	int	tmp;

	if (stack->top < 1)
	{
		append_node(ops, SB);
		return ;
	}
	tmp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = tmp;
	append_node(ops, SB);
}

void	ss(t_stack *a, t_stack *b, t_list *ops)
{
	sa(a, ops);
	sb(b, ops);
}

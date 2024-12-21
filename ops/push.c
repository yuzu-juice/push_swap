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

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top == -1)
		return ;
	(stack_a->top)++;
	stack_a->stack[stack_a->top] = stack_b->stack[stack_b->top];
	(stack_b->top)--;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top == -1)
		return ;
	(stack_b->top)++;
	stack_b->stack[stack_b->top] = stack_a->stack[stack_a->top];
	(stack_a->top)--;
	ft_printf("pb\n");
}

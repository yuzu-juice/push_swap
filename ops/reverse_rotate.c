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

void	rra(t_stack *stack_a)
{
	int	tmp;
	int	i;

	tmp = stack_a->stack[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->stack[i] = stack_a->stack[i + 1];
		i++;
	}
	stack_a->stack[stack_a->top] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	int	tmp;
	int	i;

	tmp = stack_b->stack[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->stack[i] = stack_b->stack[i + 1];
		i++;
	}
	stack_b->stack[stack_b->top] = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

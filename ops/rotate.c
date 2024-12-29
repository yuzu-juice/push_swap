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

void	ra(t_stack *a, t_list *ops)
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
	append_node(ops, RA);
}

void	rb(t_stack *b, t_list *ops)
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
	append_node(ops, RB);
}

void	rr(t_stack *a, t_stack *b, t_list *ops)
{
	ra(a, ops);
	rb(b, ops);
}

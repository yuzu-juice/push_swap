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

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	(a->top)++;
	a->stack[a->top] = b->stack[b->top];
	(b->top)--;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	(b->top)++;
	b->stack[b->top] = a->stack[a->top];
	(a->top)--;
	ft_printf("pb\n");
}

void	papa(t_stack *a, t_stack *b)
{
	pa(a, b);
	pa(a, b);
}

void	pbpb(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
}

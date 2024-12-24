/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_lte_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:28:04 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 17:32:08 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_b_two(t_stack *stack)
{
	if (stack->stack[stack->top - 1] < stack->stack[stack->top])
		sb(stack);
}

static void	sort_b_three(t_stack *a, t_stack *b)
{
	int	tmp_stack[3];
	int	min_num_index;

	ft_memmove(tmp_stack, &b->stack[b->top - 2], sizeof(int) * 3);
	min_num_index = get_min_num_index(tmp_stack, 3);
	if (min_num_index == 2)
	{
		pa(a, b);
		sort_b_two(b);
		pb(a, b);
	}
	else if (min_num_index == 1)
	{
		rb(b);
		pa(a, b);
		rrb(b);
		sort_b_two(b);
		pb(a, b);
	}
	else if (min_num_index == 0)
	{
		sort_b_two(b);
		pa(a, b);
		pa(a, b);
		rb(b);
		pb(a, b);
		pb(a, b);
		rrb(b);
	}
}

static void	sort_b_four(t_stack *a, t_stack *b)
{
	int	tmp_stack[4];
	int	min_num_index;
	int	i;

	ft_memmove(tmp_stack, &b->stack[b->top - 3], sizeof(int) * 4);
	min_num_index = get_min_num_index(tmp_stack, 4);
	i = 0;
	while (i < 4 - min_num_index - 1)
	{
		rb(b);
		i++;
	}
	pa(a, b);
	while (i > 0)
	{
		rrb(b);
		i--;
	}
	sort_b_three(a, b);
	pb(a, b);
}

void	sort_b_lte_four(t_stack *a, t_stack *b, int bottom)
{
	if (is_sorted(*b))
		return ;
	if (b->top - bottom == 3)
		sort_b_four(a, b);
	else if (b->top - bottom == 2)
		sort_b_three(a, b);
	else if (b->top - bottom == 1)
		sort_b_two(b);
}

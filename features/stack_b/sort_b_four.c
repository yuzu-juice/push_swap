/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:16:29 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/08 00:16:30 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_only_four_1(t_stacks *stacks, t_list *ops, int stack[4])
{
	if (stack[0] < stack[1] && stack[0] < stack[2] && stack[0] < stack[3])
	{
		rrb(stacks, ops);
		pa(stacks, ops);
		sort_b_three(stacks, ops);
		pb(stacks, ops);
		rb(stacks, ops);
	}
	else if (stack[1] < stack[0] && stack[1] < stack[2] && stack[1] < stack[3])
	{
		apply_n_times(rb, stacks, ops, 2);
		pa(stacks, ops);
		sort_b_three(stacks, ops);
		pb(stacks, ops);
		rb(stacks, ops);
	}
}

static void	sort_only_four_2(t_stacks *stacks, t_list *ops, int stack[4])
{
	if (stack[2] < stack[0] && stack[2] < stack[1] && stack[2] < stack[3])
	{
		rb(stacks, ops);
		pa(stacks, ops);
		sort_b_three(stacks, ops);
		pb(stacks, ops);
		rb(stacks, ops);
	}
	else if (stack[3] < stack[0] && stack[3] < stack[1] && stack[3] < stack[2])
	{
		pa(stacks, ops);
		sort_b_three(stacks, ops);
		pb(stacks, ops);
		rb(stacks, ops);
	}
}

static void	sort_b_only_four(t_stacks *stacks, t_list *ops, int stack[4])
{
	sort_only_four_1(stacks, ops, stack);
	sort_only_four_2(stacks, ops, stack);
}

static void	handle_sort_four(t_stacks *stacks, t_list *ops, int min_index)
{
	if (min_index == 0)
		sort_b_three(stacks, ops);
	else if (min_index == 1)
	{
		apply_n_times(rb, stacks, ops, 2);
		sb(stacks, ops);
		apply_n_times(rrb, stacks, ops, 2);
		sort_b_four(stacks, ops);
	}
	else if (min_index == 2)
	{
		rb(stacks, ops);
		sb(stacks, ops);
		rrb(stacks, ops);
		sort_b_four(stacks, ops);
	}
	else if (min_index == 3)
	{
		sb(stacks, ops);
		sort_b_four(stacks, ops);
	}
}

void	sort_b_four(t_stacks *stacks, t_list *ops)
{
	int		tmp_stack[4];
	int		min_index;
	t_stack	*b;

	b = &stacks->b;
	ft_memmove(tmp_stack, &b->stack[b->top - 3], sizeof(int) * 4);
	min_index = get_min_num_index(tmp_stack, 4);
	if (b->top == 3)
	{
		sort_b_only_four(stacks, ops, tmp_stack);
		return ;
	}
	handle_sort_four(stacks, ops, min_index);
}

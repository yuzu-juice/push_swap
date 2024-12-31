/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:41:23 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/31 12:47:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_only_four_1(t_stacks *stacks, t_list *ops, int stack[4])
{
	if (stack[0] > stack[1] && stack[0] > stack[2] && stack[0] > stack[3])
	{
		rra(stacks, ops);
		pb(stacks, ops);
		sort_a_three(stacks, ops);
		pa(stacks, ops);
		ra(stacks, ops);
	}
	else if (stack[1] > stack[0] && stack[1] > stack[2] && stack[1] > stack[3])
	{
		apply_n_times(ra, stacks, ops, 2);
		pb(stacks, ops);
		sort_a_three(stacks, ops);
		pa(stacks, ops);
		ra(stacks, ops);
	}
}

static void	sort_only_four_2(t_stacks *stacks, t_list *ops, int stack[4])
{
	if (stack[2] > stack[0] && stack[2] > stack[1] && stack[2] > stack[3])
	{
		ra(stacks, ops);
		pb(stacks, ops);
		sort_a_three(stacks, ops);
		pa(stacks, ops);
		ra(stacks, ops);
	}
	else if (stack[3] > stack[0] && stack[3] > stack[1] && stack[3] > stack[2])
	{
		pb(stacks, ops);
		sort_a_three(stacks, ops);
		pa(stacks, ops);
		ra(stacks, ops);
	}
}

static void	sort_a_only_four(t_stacks *stacks, t_list *ops, int stack[4])
{
	sort_only_four_1(stacks, ops, stack);
	sort_only_four_2(stacks, ops, stack);
}

static void	handle_sort_four(t_stacks *stacks, t_list *ops, int max_index)
{
	if (max_index == 0)
		sort_a_three(stacks, ops);
	else if (max_index == 1)
	{
		apply_n_times(ra, stacks, ops, 2);
		sa(stacks, ops);
		apply_n_times(rra, stacks, ops, 2);
		sort_a_four(stacks, ops);
	}
	else if (max_index == 2)
	{
		ra(stacks, ops);
		sa(stacks, ops);
		rra(stacks, ops);
		sort_a_four(stacks, ops);
	}
	else if (max_index == 3)
	{
		sa(stacks, ops);
		sort_a_four(stacks, ops);
	}
}

void	sort_a_four(t_stacks *stacks, t_list *ops)
{
	int		tmp_stack[4];
	int		max_index;
	t_stack	*a;

	a = &stacks->a;
	ft_memmove(tmp_stack, &a->stack[a->top - 3], sizeof(int) * 4);
	max_index = get_max_num_index(tmp_stack, 4);
	if (a->top == 3)
	{
		sort_a_only_four(stacks, ops, tmp_stack);
		return ;
	}
	handle_sort_four(stacks, ops, max_index);
}

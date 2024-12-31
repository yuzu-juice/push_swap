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

static void	sort_only_four_1(t_stack *a, t_stack *b, t_list *ops, int stack[4])
{
	if (stack[0] > stack[1] && stack[0] > stack[2] && stack[0] > stack[3])
	{
		rra(a, ops);
		pb(a, b, ops);
		sort_a_three(a, ops);
		pa(a, b, ops);
		ra(a, ops);
	}
	else if (stack[1] > stack[0] && stack[1] > stack[2] && stack[1] > stack[3])
	{
		rotate_n_times(ra, a, ops, 2);
		pb(a, b, ops);
		sort_a_three(a, ops);
		pa(a, b, ops);
		ra(a, ops);
	}
}

static void	sort_only_four_2(t_stack *a, t_stack *b, t_list *ops, int stack[4])
{
	if (stack[2] > stack[0] && stack[2] > stack[1] && stack[2] > stack[3])
	{
		ra(a, ops);
		pb(a, b, ops);
		sort_a_three(a, ops);
		pa(a, b, ops);
		ra(a, ops);
	}
	else if (stack[3] > stack[0] && stack[3] > stack[1] && stack[3] > stack[2])
	{
		pb(a, b, ops);
		sort_a_three(a, ops);
		pa(a, b, ops);
		ra(a, ops);
	}
}

static void	sort_a_only_four(t_stack *a, t_stack *b, t_list *ops, int stack[4])
{
	sort_only_four_1(a, b, ops, stack);
	sort_only_four_2(a, b, ops, stack);
}

static void	handle_sort_four(t_stack *a, t_stack *b, t_list *ops, int max_index)
{
	if (max_index == 0)
		sort_a_three(a, ops);
	else if (max_index == 1)
	{
		rotate_n_times(ra, a, ops, 2);
		sa(a, ops);
		rotate_n_times(rra, a, ops, 2);
		sort_a_four(a, b, ops);
	}
	else if (max_index == 2)
	{
		ra(a, ops);
		sa(a, ops);
		rra(a, ops);
		sort_a_four(a, b, ops);
	}
	else if (max_index == 3)
	{
		sa(a, ops);
		sort_a_four(a, b, ops);
	}
}

void	sort_a_four(t_stack *a, t_stack *b, t_list *ops)
{
	int	tmp_stack[4];
	int	max_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 3], sizeof(int) * 4);
	max_index = get_max_num_index(tmp_stack, 4);
	if (a->top == 3)
	{
		sort_a_only_four(a, b, ops, tmp_stack);
		return ;
	}
	handle_sort_four(a, b, ops, max_index);
}

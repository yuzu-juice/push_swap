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

static void	sort_b_two(t_stacks *stacks, t_list *ops)
{
	t_stack	*b;

	b = &stacks->b;
	if (b->stack[b->top] < b->stack[b->top - 1])
		sb(stacks, ops);
}

static void	sort_b_three(t_stacks *stacks, t_list *ops)
{
	int		tmp_stack[3];
	int		min_index;
	t_stack	*b;

	b = &stacks->b;
	ft_memmove(tmp_stack, &b->stack[b->top - 2], sizeof(int) * 3);
	min_index = get_min_num_index(tmp_stack, 3);
	if (min_index == 0)
		sb(stacks, ops);
	else if (min_index == 1)
	{
		rb(stacks, ops);
		sort_b_two(stacks, ops);
		rrb(stacks, ops);
		sort_b_two(stacks, ops);
	}
	else if (min_index == 2)
	{
		sb(stacks, ops);
		sort_b_three(stacks, ops);
	}
}

void	sort_b_lte_three(t_stacks *stacks, t_list *ops)
{
	int		size;
	t_stack	*b;

	b = &stacks->b;
	size = b->top - b->bottom + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_b_two(stacks, ops);
	else if (size == 3)
		sort_b_three(stacks, ops);
}

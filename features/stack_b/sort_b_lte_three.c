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

static void	sort_b_two(t_stack *b, t_list *ops)
{
	if (b->stack[b->top - 1] > b->stack[b->top])
		sb(b, ops);
}

static void	sort_b_three(t_stack *a, t_stack *b, t_list *ops)
{
	int	tmp_stack[3];
	int	max_num_index;

	ft_memmove(tmp_stack, &b->stack[b->top - 2], sizeof(int) * 3);
	max_num_index = get_max_num_index(tmp_stack, 3);
	if (max_num_index == 2)
	{
		pa(a, b, ops);
		sort_b_two(b, ops);
		pb(a, b, ops);
	}
	else if (max_num_index == 1)
	{
		sb(b, ops);
		sort_b_three(a, b, ops);
	}
	else if (max_num_index == 0)
	{
		sort_b_two(b, ops);
		push_n_times(pa, &(t_stacks){a, b}, ops, 2);
		rb(b, ops);
		push_n_times(pb, &(t_stacks){a, b}, ops, 2);
		rrb(b, ops);
	}
}

void	sort_b_lte_three(t_stack *a, t_stack *b, t_list *ops)
{
	if (is_sorted(b, FALSE))
		return ;
	if (b->top - b->bottom == 2)
		sort_b_three(a, b, ops);
	else if (b->top - b->bottom == 1)
		sort_b_two(b, ops);
}

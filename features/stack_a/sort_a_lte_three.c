/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_lte_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:28:03 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 17:31:57 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_a_two(t_stack *a, t_list *ops)
{
	if (a->stack[a->top - 1] < a->stack[a->top])
		sa(a, ops);
}

static void	sort_a_three(t_stack *a, t_stack *b, t_list *ops)
{
	int	tmp_stack[3];
	int	min_num_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 3);
	min_num_index = get_min_num_index(tmp_stack, 3);
	if (min_num_index == 2)
	{
		pb(a, b, ops);
		sort_a_two(a, ops);
		pa(a, b, ops);
	}
	else if (min_num_index == 1)
	{
		sa(a, ops);
		sort_a_three(a, b, ops);
	}
	else if (min_num_index == 0)
	{
		sort_a_two(a, ops);
		push_n_times(pb, &(t_stacks){a, b}, ops, 2);
		ra(a, ops);
		push_n_times(pa, &(t_stacks){a, b}, ops, 2);
		rra(a, ops);
	}
}

void	sort_a_lte_three(t_stack *a, t_stack *b, t_list *ops)
{
	if (is_sorted(a, TRUE))
		return ;
	if (a->top - a->bottom == 2)
		sort_a_three(a, b, ops);
	else if (a->top - a->bottom == 1)
		sort_a_two(a, ops);
}

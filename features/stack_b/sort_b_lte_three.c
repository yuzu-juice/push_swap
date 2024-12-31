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
	if (b->stack[b->top] < b->stack[b->top - 1])
		sb(b, ops);
}


static void	sort_b_three(t_stack *b, t_list *ops)
{
	int	tmp_stack[3];
	int	min_index;

	ft_memmove(tmp_stack, &b->stack[b->top - 2], sizeof(int) * 3);
	min_index = get_min_num_index(tmp_stack, 3);
	if (min_index == 0)
		sb(b, ops);
	else if (min_index == 1)
	{
		rb(b, ops);
		sort_b_two(b, ops);
		rrb(b, ops);
		sort_b_two(b, ops);
	}
	else if (min_index == 2)
	{
		sb(b, ops);
		sort_b_three(b, ops);
	}
}


void	sort_b_lte_three(t_stack *b, t_list *ops)
{
	int	size;

	size = b->top - b->bottom + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_b_two(b, ops);
	else if (size == 3)
		sort_b_three(b, ops);
}

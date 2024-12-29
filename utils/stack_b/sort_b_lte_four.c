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

static void	sort_b_two(t_stack *stack, t_list *ops)
{
	if (stack->stack[stack->top - 1] < stack->stack[stack->top])
		sb(stack, ops);
}

static void	sort_b_three(t_stack *a, t_stack *b, t_list *ops)
{
	int	tmp_stack[3];
	int	min_num_index;

	ft_memmove(tmp_stack, &b->stack[b->top - 2], sizeof(int) * 3);
	min_num_index = get_min_num_index(tmp_stack, 3);
	if (min_num_index == 2)
	{
		pa(a, b, ops);
		sort_b_two(b, ops);
		pb(a, b, ops);
	}
	else if (min_num_index == 1)
	{
		pa2(a, b, ops);
		sort_b_two(b, ops);
		pb(a, b, ops);
	}
	else if (min_num_index == 0)
	{
		sort_b_two(b, ops);
		papa(a, b, ops);
		rb(b, ops);
		pbpb(a, b, ops);
		rrb(b, ops);
	}
}

static void	sort_b_four(t_stack *a, t_stack *b, t_list *ops)
{
	int	tmp_stack[4];
	int	min_num_index;
	int	i;

	ft_memmove(tmp_stack, &b->stack[b->top - 3], sizeof(int) * 4);
	min_num_index = get_min_num_index(tmp_stack, 4);
	i = 0;
	while (i < 4 - min_num_index - 1)
	{
		rb(b, ops);
		i++;
	}
	pa(a, b, ops);
	while (i > 0)
	{
		rrb(b, ops);
		i--;
	}
	sort_b_three(a, b, ops);
	pb(a, b, ops);
}

void	sort_b_lte_four(t_stack *a, t_stack *b, t_list *ops)
{
	if (is_sorted(*b))
		return ;
	if (b->top - b->bottom == 3)
		sort_b_four(a, b, ops);
	else if (b->top - b->bottom == 2)
		sort_b_three(a, b, ops);
	else if (b->top - b->bottom == 1)
		sort_b_two(b, ops);
}

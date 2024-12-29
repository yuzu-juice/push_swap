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

static void	sort_a_two(t_stack *stack, t_list *ops)
{
	if (stack->stack[stack->top - 1] < stack->stack[stack->top])
		sa(stack, ops);
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
		pb2(a, b, ops);
		sort_a_two(a, ops);
		pa(a, b, ops);
	}
	else if (min_num_index == 0)
	{
		sort_a_two(a, ops);
		pbpb(a, b, ops);
		ra(a, ops);
		papa(a, b, ops);
		rra(a, ops);
	}
}

static void	sort_a_four(t_stack *a, t_stack *b, t_list *ops)
{
	int	tmp_stack[4];
	int	min_num_index;
	int	i;

	ft_memmove(tmp_stack, &a->stack[a->top - 3], sizeof(int) * 4);
	min_num_index = get_min_num_index(tmp_stack, 4);
	i = 0;
	while (i < 4 - min_num_index - 1)
	{
		ra(a, ops);
		i++;
	}
	pb(a, b, ops);
	while (i > 0)
	{
		rra(a, ops);
		i--;
	}
	sort_a_three(a, b, ops);
	pa(a, b, ops);
}

void	sort_a_lte_four(t_stack *a, t_stack *b, t_list *ops)
{
	if (is_sorted(*a))
		return ;
	if (a->top - a->bottom == 3)
		sort_a_four(a, b, ops);
	else if (a->top - a->bottom == 2)
		sort_a_three(a, b, ops);
	else if (a->top - a->bottom == 1)
		sort_a_two(a, ops);
}

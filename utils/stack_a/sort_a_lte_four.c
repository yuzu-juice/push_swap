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

static void	sort_a_two(t_stack *stack)
{
	if (stack->stack[stack->top - 1] < stack->stack[stack->top])
		sa(stack);
}

static void	sort_a_three(t_stack *a, t_stack *b)
{
	int	tmp_stack[3];
	int	min_num_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 3);
	min_num_index = get_min_num_index(tmp_stack, 3);
	if (min_num_index == 2)
	{
		pb(a, b);
		sort_a_two(a);
		pa(a, b);
	}
	else if (min_num_index == 1)
	{
		pb2(a, b);
		sort_a_two(a);
		pa(a, b);
	}
	else if (min_num_index == 0)
	{
		sort_a_two(a);
		pbpb(a, b);
		ra(a);
		papa(a, b);
		rra(a);
	}
}

static void	sort_a_four(t_stack *a, t_stack *b)
{
	int	tmp_stack[4];
	int	min_num_index;
	int	i;

	ft_memmove(tmp_stack, &a->stack[a->top - 3], sizeof(int) * 4);
	min_num_index = get_min_num_index(tmp_stack, 4);
	i = 0;
	while (i < 4 - min_num_index - 1)
	{
		ra(a);
		i++;
	}
	pb(a, b);
	while (i > 0)
	{
		rra(a);
		i--;
	}
	sort_a_three(a, b);
	pa(a, b);
}

void	sort_a_lte_four(t_stack *a, t_stack *b, int bottom)
{
	if (is_sorted(*a))
		return ;
	if (a->top - bottom == 3)
		sort_a_four(a, b);
	else if (a->top - bottom == 2)
		sort_a_three(a, b);
	else if (a->top - bottom == 1)
		sort_a_two(a);
}

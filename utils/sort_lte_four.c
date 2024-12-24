/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:25:47 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 00:36:42 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

_Bool	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.top)
	{
		if (stack.stack[i] < stack.stack[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	sort_two(t_stack *stack)
{
	if (stack->stack[stack->top - 1] < stack->stack[stack->top])
		sa(stack);
}

static void	sort_three(t_stack *a, t_stack *b)
{
	int	tmp_stack[3];
	int	min_num_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 3);
	min_num_index = get_min_num_index(tmp_stack, 3);
	if (min_num_index == 2)
	{
		pb(a, b);
		sort_two(a);
		pa(a, b);
	}
	else if (min_num_index == 1)
	{
		ra(a);
		pb(a, b);
		rra(a);
		sort_two(a);
		pa(a, b);
	}
	else if (min_num_index == 0)
	{
		pb(a, b);
		sort_two(a);
		pa(a, b);
	}
}

static void	sort_four(t_stack *a, t_stack *b)
{
	int tmp_stack[4];
	int	min_num_index;
	int	i;

	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 4);
	min_num_index = get_min_num_index(a->stack, 4);
	i = 0;
	while (i < a->top - min_num_index)
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
	sort_three(a, b);
	pa(a, b);
}

void sort_lte_four(t_stack *a, t_stack *b, int bottom)
{
	if (is_sorted(*a))
		return ;
	if (a->top - bottom == 3)
		sort_four(a, b);
	else if (a->top - bottom == 2)
		sort_three(a, b);
	else if (a->top - bottom == 1)
		sort_two(a);
}
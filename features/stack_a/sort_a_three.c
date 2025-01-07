/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:46:40 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/31 12:47:10 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_a_only_three(t_stacks *stacks, t_list *ops, int stack[3])
{
	if (stack[0] > stack[1] && stack[0] > stack[2])
		sort_a_two(stacks, ops);
	else if (stack[2] > stack[0] && stack[2] > stack[1])
	{
		ra(stacks, ops);
		sort_a_two(stacks, ops);
	}
	else if (stack[1] > stack[0] && stack[1] > stack[2])
	{
		rra(stacks, ops);
		sort_a_two(stacks, ops);
	}
}

static void	handle_sort_three(t_stacks *stacks, t_list *ops, int stack[3])
{
	if (stack[0] > stack[1] && stack[0] > stack[2])
		sort_a_two(stacks, ops);
	else if (stack[1] > stack[0] && stack[1] > stack[2])
	{
		ra(stacks, ops);
		sort_a_two(stacks, ops);
		rra(stacks, ops);
		sort_a_two(stacks, ops);
	}
	else if (stack[2] > stack[0] && stack[2] > stack[1])
	{
		sa(stacks, ops);
		sort_a_three(stacks, ops);
	}
}

void	sort_a_three(t_stacks *stacks, t_list *ops)
{
	int		tmp_stack[3];
	t_stack	*a;

	a = &stacks->a;
	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 3);
	if (a->top == 2 && a->bottom == 0)
	{
		sort_a_only_three(stacks, ops, tmp_stack);
		return ;
	}
	handle_sort_three(stacks, ops, tmp_stack);
}

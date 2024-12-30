/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_lte_three.c                                 :+:      :+:    :+:   */
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
	if (a->stack[a->top] > a->stack[a->top - 1])
		sa(a, ops);
}

static void	sort_a_three(t_stack *a, t_list *ops)
{
	int	tmp_stack[3];
	int	max_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 3);
	max_index = get_max_num_index(tmp_stack, 3);
	if (max_index == 0)
		sa(a, ops);
	else if (max_index == 1)
	{
		ra(a, ops);
		sort_a_two(a, ops);
		rra(a, ops);
		sort_a_two(a, ops);
	}
	else if (max_index == 2)
	{
		sa(a, ops);
		sort_a_three(a, ops);
	}
}

void	sort_a_lte_three(t_stack *a, t_list *ops)
{
	int	size;

	size = a->top - a->bottom + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_a_two(a, ops);
	else if (size == 3)
		sort_a_three(a, ops);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:41:23 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/31 12:47:43 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	handle_max_index_0(t_stack *a, t_list *ops)
{
	sort_a_three(a, ops);
}

static void	handle_max_index_1(t_stack *a, t_list *ops)
{
	rotate_n_times(ra, a, ops, 2);
	sa(a, ops);
	rotate_n_times(rra, a, ops, 2);
	sort_a_four(a, ops);
}

static void	handle_max_index_2(t_stack *a, t_list *ops)
{
	ra(a, ops);
	sa(a, ops);
	rra(a, ops);
	sort_a_four(a, ops);
}

static void	handle_max_index_3(t_stack *a, t_list *ops)
{
	sa(a, ops);
	sort_a_four(a, ops);
}

void	sort_a_four(t_stack *a, t_list *ops)
{
	int	tmp_stack[4];
	int	max_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 3], sizeof(int) * 4);
	max_index = get_max_num_index(tmp_stack, 4);
	if (max_index == 0)
		handle_max_index_0(a, ops);
	else if (max_index == 1)
		handle_max_index_1(a, ops);
	else if (max_index == 2)
		handle_max_index_2(a, ops);
	else if (max_index == 3)
		handle_max_index_3(a, ops);
}

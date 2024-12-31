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

void	sort_a_three(t_stack *a, t_list *ops)
{
	int	tmp_stack[3];
	int	max_index;

	ft_memmove(tmp_stack, &a->stack[a->top - 2], sizeof(int) * 3);
	max_index = get_max_num_index(tmp_stack, 3);
	if (max_index == 0)
		sort_a_two(a, ops);
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

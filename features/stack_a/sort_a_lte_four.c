/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_lte_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:01:42 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/31 12:47:05 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_a_lte_four(t_stack *a, t_stack *b, t_list *ops)
{
	int	size;

	size = a->top - a->bottom + 1;
	if (size <= 1)
		return ;
	else if (size == 2)
		sort_a_two(a, ops);
	else if (size == 3)
		sort_a_three(a, ops);
	else if (size == 4)
		sort_a_four(a, b, ops);
}

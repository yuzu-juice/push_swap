/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:21:21 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/29 23:34:49 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*b;

	a = &stacks->a;
	b = &stacks->b;
	free(a->stack);
	free(b->stack);
}

void	free_ops(t_list *ops)
{
	t_list	*current;
	t_list	*next;

	current = ops->next;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	ops->next = NULL;
}

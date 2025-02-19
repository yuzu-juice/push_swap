/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:03:06 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 16:04:28 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	append_node(t_stacks *stacks, t_list *ops, t_ops op)
{
	t_list	*op_node;
	t_list	*current;

	current = ops;
	op_node = ft_calloc(1, sizeof(t_list));
	if (!op_node)
	{
		free_stack(stacks);
		free_ops(ops);
		exit (EXIT_FAILURE);
	}
	op_node->value = op;
	op_node->next = NULL;
	while (current->next)
		current = current->next;
	current->next = op_node;
}

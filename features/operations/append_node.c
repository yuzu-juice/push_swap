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

t_list	*get_last_node(t_list *ops)
{
	t_list	*current;

	current = ops;
	while (current->next)
		current = current->next;
	return (current);
}

void	append_node(t_stacks *stacks, t_list *ops, t_ops op)
{
	t_list	*op_node;
	t_list	*last_node;

	op_node = malloc(sizeof(t_list));
	if (!op_node)
	{
		finalize(stacks, ops);
		exit (EXIT_FAILURE);
	}
	last_node = get_last_node(ops);
	op_node->value = op;
	op_node->next = NULL;
	op_node->prev = last_node;
	last_node->next = op_node;
}


void	remove_last_node(t_list *ops)
{
	t_list	*last_node;
	t_list	*current;

	last_node = get_last_node(ops);
	current = ops;
	while (current->next != last_node)
		current = current->next;
	current->next = NULL;
	free(last_node);
}

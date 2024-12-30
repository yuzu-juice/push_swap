/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:03:12 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 16:16:39 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static _Bool	delete_pa_pb(t_list *ops)
{
	t_list	*current;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	current = ops;
	has_called = FALSE;
	while (current && current->next && current->next->next)
	{
		n = current->next->value;
		nn = current->next->next->value;
		if ((n == PA && nn == PB) || (n == PB && nn == PA))
		{
			tmp = current->next->next->next;
			free(current->next);
			free(current->next->next);
			current->next = tmp;
			has_called = TRUE;
		}
		else
			current = current->next;
	}
	return (has_called);
}

static _Bool	delete_ra_rra(t_list *ops)
{
	t_list	*current;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	current = ops;
	has_called = FALSE;
	while (current && current->next && current->next->next)
	{
		n = current->next->value;
		nn = current->next->next->value;
		if ((n == RA && nn == RRA) || (n == RRA && nn == RA))
		{
			tmp = current->next->next->next;
			free(current->next);
			free(current->next->next);
			current->next = tmp;
			has_called = TRUE;
		}
		else
			current = current->next;
	}
	return (has_called);
}

static _Bool	delete_rb_rrb(t_list *ops)
{
	t_list	*current;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	current = ops;
	has_called = FALSE;
	while (current && current->next && current->next->next)
	{
		n = current->next->value;
		nn = current->next->next->value;
		if ((n == RB && nn == RRB) || (n == RRB && nn == RB))
		{
			tmp = current->next->next->next;
			free(current->next);
			free(current->next->next);
			current->next = tmp;
			has_called = TRUE;
		}
		else
			current = current->next;
	}
	return (has_called);
}

void	optimize_ops(t_list *ops)
{
	_Bool	is_finished;

	is_finished = TRUE;
	if (delete_pa_pb(ops))
		is_finished = FALSE;
	if (delete_ra_rra(ops))
		is_finished = FALSE;
	if (delete_rb_rrb(ops))
		is_finished = FALSE;
	if (!is_finished)
		optimize_ops(ops);
}

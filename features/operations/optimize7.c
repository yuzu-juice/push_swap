/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:00:40 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/01 01:00:40 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

_Bool	compress_sb_any_a_sa(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == SB && cur->next->next->value == RA
				&& cur->next->next->next->value == SA)
			|| (cur->next->value == SB && cur->next->next->value == RRA
				&& cur->next->next->next->value == SA))
		{
			cur->next->next->next->value = SS;
			tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_rb_any_a_ra(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RB && cur->next->next->value == SA
				&& cur->next->next->next->value == RA)
			|| (cur->next->value == RB && cur->next->next->value == RRA
				&& cur->next->next->next->value == RA))
		{
			cur->next->next->next->value = RR;
			tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_rrb_any_a_rra(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RRB && cur->next->next->value == SA
				&& cur->next->next->next->value == RRA)
			|| (cur->next->value == RRB && cur->next->next->value == RA
				&& cur->next->next->next->value == RRA))
		{
			cur->next->next->next->value = RRR;
			tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

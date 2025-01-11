/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:10:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/01 00:30:16 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

_Bool	compress_sb_any_b_sa(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == SB && cur->next->next->value == RB
				&& cur->next->next->next->value == SA)
			|| (cur->next->value == SB && cur->next->next->value == RRB
				&& cur->next->next->next->value == SA))
		{
			tmp = cur->next->next->next->next;
			free(cur->next->next->next);
			cur->next->value = SS;
			cur->next->next->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_rb_any_b_ra(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RB && cur->next->next->value == SB
				&& cur->next->next->next->value == RA)
			|| (cur->next->value == RB && cur->next->next->value == RB
				&& cur->next->next->next->value == RA))
		{
			tmp = cur->next->next->next->next;
			free(cur->next->next->next);
			cur->next->value = RR;
			cur->next->next->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_rrb_any_b_rra(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RRB && cur->next->next->value == SB
				&& cur->next->next->next->value == RRA)
			|| (cur->next->value == RRB && cur->next->next->value == RRB
				&& cur->next->next->next->value == RRA))
		{
			tmp = cur->next->next->next->next;
			free(cur->next->next->next);
			cur->next->value = RRR;
			cur->next->next->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:52:45 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/01 00:52:53 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

_Bool	compress_sa_any_b_sb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == SA && cur->next->next->value == RB
				&& cur->next->next->next->value == SB)
			|| (cur->next->value == SA && cur->next->next->value == RRB
				&& cur->next->next->next->value == SB))
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

_Bool	compress_ra_any_b_rb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RA && cur->next->next->value == SB
				&& cur->next->next->next->value == RB)
			|| (cur->next->value == RA && cur->next->next->value == RRB
				&& cur->next->next->next->value == RB))
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

_Bool	compress_rra_any_b_rrb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RRA && cur->next->next->value == SB
				&& cur->next->next->next->value == RRB)
			|| (cur->next->value == RRA && cur->next->next->value == RB
				&& cur->next->next->next->value == RRB))
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

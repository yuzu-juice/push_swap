/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:10:50 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/01 00:30:16 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

_Bool	compress_sa_any_a_sb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == SA && cur->next->next->value == RA
				&& cur->next->next->next->value == SB)
			|| (cur->next->value == SA && cur->next->next->value == RRA
				&& cur->next->next->next->value == SB))
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

_Bool	compress_ra_any_a_rb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RA && cur->next->next->value == SA
				&& cur->next->next->next->value == RB)
			|| (cur->next->value == RA && cur->next->next->value == RA
				&& cur->next->next->next->value == RB))
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

_Bool	compress_rra_any_a_rrb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if ((cur->next->value == RRA && cur->next->next->value == SA
				&& cur->next->next->next->value == RRB)
			|| (cur->next->value == RRA && cur->next->next->value == RRA
				&& cur->next->next->next->value == RRB))
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

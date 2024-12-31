/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:03:12 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/31 15:37:20 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

_Bool	delete_pa_pb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next)
	{
		n = cur->next->value;
		nn = cur->next->next->value;
		if ((n == PA && nn == PB) || (n == PB && nn == PA))
		{
			tmp = cur->next->next->next;
			free(cur->next->next);
			free(cur->next);
			cur->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	delete_ra_rra(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next)
	{
		n = cur->next->value;
		nn = cur->next->next->value;
		if ((n == RA && nn == RRA) || (n == RRA && nn == RA))
		{
			tmp = cur->next->next->next;
			free(cur->next->next);
			free(cur->next);
			cur->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	delete_rb_rrb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next)
	{
		n = cur->next->value;
		nn = cur->next->next->value;
		if ((n == RB && nn == RRB) || (n == RRB && nn == RB))
		{
			tmp = cur->next->next->next;
			free(cur->next->next);
			free(cur->next);
			cur->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_sa_sb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	t_ops	n;
	t_ops	nn;
	_Bool	has_called;

	cur = ops;
	has_called = false;
	while (cur && cur->next && cur->next->next)
	{
		n = cur->next->value;
		nn = cur->next->next->value;
		if ((n == SA && nn == SB) || (n == SB && nn == SA))
		{
			tmp = cur->next->next->next;
			free(cur->next->next);
			cur->next->value = SS;
			cur->next->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

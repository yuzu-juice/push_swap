/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:03:55 by takitaga          #+#    #+#             */
/*   Updated: 2025/01/01 00:11:10 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

_Bool	compress_ra_rb(t_list *ops)
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
		if ((n == RA && nn == RB) || (n == RB && nn == RA))
		{
			tmp = cur->next->next->next;
			free(cur->next->next);
			cur->next->value = RR;
			cur->next->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_rra_rrb(t_list *ops)
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
		if ((n == RRA && nn == RRB) || (n == RRB && nn == RRA))
		{
			tmp = cur->next->next->next;
			free(cur->next->next);
			cur->next->value = RRR;
			cur->next->next = tmp;
			has_called = true;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

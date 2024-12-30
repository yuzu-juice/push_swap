/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:48:52 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 21:51:54 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

_Bool	compress_ra_pb_rra(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = FALSE;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if (cur->next->value == RA && cur->next->next->value == PB
			&& cur->next->next->next->value == RRA)
		{
			tmp = cur->next->next->next->next;
			cur->next->value = SA;
			cur->next->next->value = PB;
			free(cur->next->next->next);
			cur->next->next->next = tmp;
			has_called = TRUE;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

_Bool	compress_rb_pa_rrb(t_list *ops)
{
	t_list	*cur;
	t_list	*tmp;
	_Bool	has_called;

	cur = ops;
	has_called = FALSE;
	while (cur && cur->next && cur->next->next && cur->next->next->next)
	{
		if (cur->next->value == RB && cur->next->next->value == PA
			&& cur->next->next->next->value == RRB)
		{
			tmp = cur->next->next->next->next;
			cur->next->value = SB;
			cur->next->next->value = PA;
			free(cur->next->next->next);
			cur->next->next->next = tmp;
			has_called = TRUE;
		}
		else
			cur = cur->next;
	}
	return (has_called);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:50:30 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 21:51:31 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static _Bool	optimize_ops_1(t_list *ops)
{
	_Bool	any_changes;

	any_changes = false;
	if (delete_pa_pb(ops))
		any_changes = true;
	if (delete_ra_rra(ops))
		any_changes = true;
	if (delete_rb_rrb(ops))
		any_changes = true;
	if (compress_ra_pb_rra(ops))
		any_changes = true;
	if (compress_rb_pa_rrb(ops))
		any_changes = true;
	if (compress_sa_sb(ops))
		any_changes = true;
	if (compress_ra_rb(ops))
		any_changes = true;
	if (compress_rra_rrb(ops))
		any_changes = true;
	if (compress_sa_any_a_sb(ops))
		any_changes = true;
	if (compress_ra_any_a_rb(ops))
		any_changes = true;
	return (any_changes);
}

static _Bool	optimize_ops_2(t_list *ops)
{
	_Bool	any_changes;

	any_changes = false;
	if (compress_rra_any_a_rrb(ops))
		any_changes = true;
	if (compress_sb_any_b_sa(ops))
		any_changes = true;
	if (compress_rb_any_b_ra(ops))
		any_changes = true;
	if (compress_rrb_any_b_rra(ops))
		any_changes = true;
	if (compress_sa_any_b_sb(ops))
		any_changes = true;
	if (compress_ra_any_b_rb(ops))
		any_changes = true;
	if (compress_rra_any_b_rrb(ops))
		any_changes = true;
	if (compress_sb_any_a_sa(ops))
		any_changes = true;
	if (compress_rb_any_a_ra(ops))
		any_changes = true;
	if (compress_rrb_any_a_rra(ops))
		any_changes = true;
	return (any_changes);
}

void	optimize_ops(t_list *ops)
{
	_Bool	any_changes;

	any_changes = false;
	if (optimize_ops_1(ops))
		any_changes = true;
	if (optimize_ops_2(ops))
		any_changes = true;
	if (any_changes)
		optimize_ops(ops);
}

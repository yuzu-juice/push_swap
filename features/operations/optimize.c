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

void	optimize_ops(t_list *ops)
{
	_Bool	any_changes;

	any_changes = FALSE;
	if (delete_pa_pb(ops))
		any_changes = TRUE;
	if (delete_ra_rra(ops))
		any_changes = TRUE;
	if (delete_rb_rrb(ops))
		any_changes = TRUE;
	if (compress_sa_sb(ops))
		any_changes = TRUE;
	if (compress_ra_pb_rra(ops))
		any_changes = TRUE;
	if (compress_rb_pa_rrb(ops))
		any_changes = TRUE;
	if (any_changes)
		optimize_ops(ops);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:13:56 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/29 23:37:33 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_ops_swap(t_list *ops)
{
	if (ops->value == SA)
		ft_printf("sa\n");
	else if (ops->value == SB)
		ft_printf("sb\n");
	else if (ops->value == SS)
		ft_printf("ss\n");
}

static void	print_ops_push(t_list *ops)
{
	if (ops->value == PA)
		ft_printf("pa\n");
	else if (ops->value == PB)
		ft_printf("pb\n");
}

static void	print_ops_rotate(t_list *ops)
{
	if (ops->value == RA)
		ft_printf("ra\n");
	else if (ops->value == RB)
		ft_printf("rb\n");
	else if (ops->value == RR)
		ft_printf("rr\n");
}

static void	print_ops_reverse_rotate(t_list *ops)
{
	if (ops->value == RRA)
		ft_printf("rra\n");
	else if (ops->value == RRB)
		ft_printf("rrb\n");
	else if (ops->value == RRR)
		ft_printf("rrr\n");
}

void	print_ops(t_list *ops)
{
	while (ops)
	{
		if (ops->value == SA || ops->value == SB || ops->value == SS)
			print_ops_swap(ops);
		else if (ops->value == PA || ops->value == PB)
			print_ops_push(ops);
		else if (ops->value == RA || ops->value == RB || ops->value == RR)
			print_ops_rotate(ops);
		else if (ops->value == RRA || ops->value == RRB || ops->value == RRR)
			print_ops_reverse_rotate(ops);
		ops = ops->next;
	}
}

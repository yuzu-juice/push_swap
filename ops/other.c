/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:28:33 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 21:42:03 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa2(t_stack *a, t_stack *b, t_list *ops)
{
	sb(b, ops);
	pa(a, b, ops);
}

void	pb2(t_stack *a, t_stack *b, t_list *ops)
{
	sa(a, ops);
	pb(a, b, ops);
}

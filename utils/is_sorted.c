/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:28:19 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 17:28:32 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

_Bool	is_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.top)
	{
		if (stack.stack[i] < stack.stack[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

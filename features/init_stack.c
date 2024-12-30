/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:13:05 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/29 23:03:16 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

_Bool	init_stack(int argc, char *argv[], t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	size;

	size = argc - 1;
	a->stack = ft_calloc(size, sizeof(int));
	if (!a->stack)
		return (FALSE);
	b->stack = ft_calloc(size, sizeof(int));
	if (!b->stack)
	{
		free(a->stack);
		return (FALSE);
	}
	a->bottom = 0;
	b->bottom = 0;
	a->top = size - 1;
	b->top = -1;
	i = 1;
	while (i <= size)
	{
		a->stack[size - i] = ft_atoi(argv[i]);
		i++;
	}
	return (TRUE);
}

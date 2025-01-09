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

_Bool	init_stack(int argc, char *argv[], t_stacks *stacks)
{
	size_t	i;
	size_t	size;

	size = argc - 1;
	stacks->a.stack = ft_calloc(size, sizeof(int));
	if (!stacks->a.stack)
		exit (EXIT_FAILURE);
	stacks->b.stack = ft_calloc(size, sizeof(int));
	if (!stacks->b.stack)
	{
		free(stacks->a.stack);
		exit (EXIT_FAILURE);
	}
	stacks->a.bottom = 0;
	stacks->b.bottom = 0;
	stacks->a.top = size - 1;
	stacks->b.top = -1;
	i = 1;
	while (i <= size)
	{
		stacks->a.stack[size - i] = ft_atoi(argv[i]);
		i++;
	}
	return (true);
}

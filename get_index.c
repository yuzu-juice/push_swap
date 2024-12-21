/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:48:53 by takitaga          #+#    #+#             */
/*   Updated: 2024/09/20 00:49:28 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(int *stack, size_t size)
{
	size_t	i;
	size_t	max_index;

	i = 0;
	max_index = i;
	i++;
	while (i < size)
	{
		if (stack[max_index] < stack[i])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	get_min_index(int *stack, size_t size)
{
	size_t	i;
	size_t	min_index;

	i = 0;
	min_index = i;
	i++;
	while (i < size)
	{
		if (stack[min_index] > stack[i])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	get_largest_num_index_lt(int *stack, size_t size, int target)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = i;
	while (i < size)
	{
		if (stack[i] < target && stack[i] > stack[index])
			index = i;
		i++;
	}
	return (index);
}

int	get_smallest_num_index_gt(int *stack, size_t size, int target)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = i;
	while (i < size)
	{
		if (stack[i] > target && stack[i] < stack[index])
			index = i;
		i++;
	}
	return (index);
}

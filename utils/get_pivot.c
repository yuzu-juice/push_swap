/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:41:13 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/24 10:36:11 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_pivot(int *stack, size_t start, size_t end)
{
	int		pivot;
	size_t	size;
	int		*tmp_stack;

	if (end <= start)
		return (-1);
	size = end - start + 1;
	tmp_stack = malloc(sizeof(int) * size);
	if (!tmp_stack)
	{
		free(tmp_stack);
		return (-1);
	}
	ft_memmove(tmp_stack, &stack[start], sizeof(int) * size);
	ft_qsort(tmp_stack, 0, size - 1);
	pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (pivot);
}

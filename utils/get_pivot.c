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

static int	find_nth_element(int *stack, size_t start, size_t end, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	count_less;
	int		target;

	i = start;
	while (i <= end)
	{
		target = stack[i];
		count_less = 0;
		j = start;
		while (j <= end)
		{
			if (stack[j] < target)
				count_less++;
			j++;
		}
		if (count_less == n)
			return (target);
		i++;
	}
	return (stack[start]);
}

int	get_pivot(int *stack, size_t start, size_t end)
{
	size_t	size;

	size = end - start + 1;
	return (find_nth_element(stack, start, end, size / 2));
}

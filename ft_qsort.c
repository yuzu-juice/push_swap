/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:02:03 by takitaga          #+#    #+#             */
/*   Updated: 2024/09/02 00:02:03 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_qsort(int *elements, size_t start, size_t end)
{
	int		pivot;
	size_t	i;
	size_t	j;

	if (start >= end)
		return ;
	pivot = elements[(start + end) / 2];
	i = start;
	j = end;
	while (true)
	{
		while (elements[i] < pivot)
			i++;
		while (elements[j] > pivot)
			j--;
		if (i >= j)
			break ;
		swap(&elements[i], &elements[j]);
		i++;
		j--;
	}
	ft_qsort(elements, start, j);
	ft_qsort(elements, j + 1, end);
}

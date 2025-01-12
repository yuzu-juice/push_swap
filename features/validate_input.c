/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:47:46 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/29 22:23:30 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static _Bool	has_duplicates(int *elements, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (i + j + 1 < size)
		{
			if (elements[i] == elements[i + j + 1])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static int	check_overflow(int sign, long l, char next)
{
	if (sign == 1)
		if (INT_MAX / 10 < l
			|| (INT_MAX / 10 == l && INT_MAX % 10 < next - '0'))
			return (1);
	if (sign == -1)
		if (INT_MIN / -10 < l
			|| (INT_MIN / -10 == l && INT_MIN % -10 * -1 < next - '0'))
			return (-1);
	return (0);
}

static _Bool	is_within_int_range(const char *nptr)
{
	long	ret_value;
	int		sign;
	size_t	i;

	ret_value = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
		if (check_overflow(sign, ret_value, nptr[i]) != 0)
			return (true);
		ret_value = ret_value * 10 + (long)(nptr[i] - '0');
		i++;
	}
	return (false);
}

_Bool	validate_input(int argc, char *argv[])
{
	int	i;
	int	*elements;

	i = 1;
	elements = ft_calloc(argc - 1, sizeof(int));
	if (!elements)
		exit (EXIT_FAILURE);
	while (i < argc)
	{
		if (!ft_isnum(argv[i]) || is_within_int_range(argv[i]))
		{
			free(elements);
			return (false);
		}
		elements[argc - i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (has_duplicates(elements, argc - 1))
	{
		free(elements);
		return (false);
	}
	free(elements);
	return (true);
}

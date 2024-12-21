/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:22:57 by takitaga          #+#    #+#             */
/*   Updated: 2024/09/09 23:56:02 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_duplicates(int *elements, int size)
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

static bool	is_within_int_range(const char *nptr)
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

bool	is_valid_num(char *num)
{
	if (!ft_isnum(num))
	{
		ft_printf("Error\n");
		return (false);
	}
	if (is_within_int_range(num))
	{
		ft_printf("Error\n");
		return (false);
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:06:49 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 14:37:44 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *a, t_stack *b, size_t size)
// {
// 	size_t	i;
// 	int		flag;

// 	i = 0;
// 	flag = TRUE;
// 	if (a->top == -1)
// 		ft_printf("a is empty.\n");
// 	while (i < size)
// 	{
// 		if (flag)
// 			ft_printf("a[%u]: %d", i, a->stack[i]);
// 		else
// 			ft_printf("a[%u]:", i);
// 		if ((size_t)a->top == i)
// 		{
// 			ft_printf(" <- top");
// 			flag = FALSE;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n");
// 	if (b->top == -1)
// 		ft_printf("b is empty.\n");
// 	i = 0;
// 	flag = TRUE;
// 	while (i < size)
// 	{
// 		if (flag)
// 			ft_printf("b[%u]: %d", i, b->stack[i]);
// 		else
// 			ft_printf("b[%u]:", i);
// 		if ((size_t)b->top == i)
// 		{
// 			ft_printf(" <- top");
// 			flag = FALSE;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n\n-------------------------\n\n");
// }

static void	push_swap_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(*a))
		return ;
	if (a->top < 4)
		sort_a_lte_four(a, b, 0);
	if (a->top >= 4)
	{
		split_by_pivot(a, b);
		sort_a(a, b, 0);
		sort_b(a, b, 0);
		while (b->top >= 0)
		{
			rrb(b);
			pa(a, b);
		}
	}
}

static void	normalize_stack(int *elements, t_stack *a, size_t size)
{
	size_t	i;
	size_t	j;

	ft_qsort(elements, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a->stack[j] == elements[i])
			{
				a->stack[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	push_swap_init(int *elements, size_t size, t_stack *a, t_stack *b)
{
	size_t	i;

	a->stack = ft_calloc(size, sizeof(int));
	b->stack = ft_calloc(size, sizeof(int));
	if (!a->stack || !b->stack)
		return ;
	a->top = size - 1;
	b->top = -1;
	i = 0;
	while (i < size)
	{
		a->stack[i] = elements[i];
		i++;
	}
	normalize_stack(elements, a, size);
}

static int	print_error(void)
{
	ft_printf("Error\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		*elements;
	t_stack	a;
	t_stack	b;

	i = 1;
	elements = malloc((argc - 1) * sizeof(int));
	if (!elements || argc == 1)
		return (print_error());
	while (i < argc)
	{
		if (!is_valid_num(argv[i]))
			return (print_error());
		elements[argc - i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (has_duplicates(elements, argc - 1))
		return (print_error());
	push_swap_init(elements, argc - 1, &a, &b);
	push_swap_sort(&a, &b);
	free(a.stack);
	free(b.stack);
	free(elements);
	return (0);
}

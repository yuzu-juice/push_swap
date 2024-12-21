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

// static void	print_stack(t_stack *stack_a, t_stack *stack_b, size_t size)
// {
// 	size_t	i;
// 	int		flag;

// 	i = 0;
// 	flag = TRUE;
// 	if (stack_a->top == -1)
// 		ft_printf("stack_a is empty.\n");
// 	while (i < size)
// 	{
// 		if (flag)
// 			ft_printf("a[%u]: %d", i, stack_a->stack[i]);
// 		else
// 			ft_printf("a[%u]:", i);
// 		if ((size_t)stack_a->top == i)
// 		{
// 			ft_printf(" <- top");
// 			flag = FALSE;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n");
// 	if (stack_b->top == -1)
// 		ft_printf("stack_b is empty.\n");
// 	i = 0;
// 	flag = TRUE;
// 	while (i < size)
// 	{
// 		if (flag)
// 			ft_printf("b[%u]: %d", i, stack_b->stack[i]);
// 		else
// 			ft_printf("b[%u]:", i);
// 		if ((size_t)stack_b->top == i)
// 		{
// 			ft_printf(" <- top");
// 			flag = FALSE;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n\n-------------------------\n\n");
// }


static void	push_swap_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (stack_a->top == 1)
		if (stack_a->stack[0] < stack_a->stack[1])
			sa(stack_a);
	if (stack_a->top == 2)
		sort_three(stack_a);
	if (stack_a->top == 3)
		sort_four(stack_a, stack_b);
	if (stack_a->top >= 4)
		sort_more_than_five(stack_a, stack_b);
}

static void normalize_stack(int *elements, t_stack *stack_a, size_t size)
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
			if (stack_a->stack[j] == elements[i])
			{
				stack_a->stack[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	push_swap_init(int *elements, size_t size, t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	stack_a->stack = ft_calloc(size, sizeof(int));
	stack_b->stack = ft_calloc(size, sizeof(int));
	if (!stack_a->stack || !stack_b->stack)
		return ;
	stack_a->top = size - 1;
	stack_b->top = -1;

	i = 0;
	while (i < size)
	{
		stack_a->stack[i] = elements[i];
		i++;
	}
	normalize_stack(elements, stack_a, size);
}

int main(int argc, char *argv[])
{
	int		i;
	int		elements[argc - 1];
	t_stack	stack_a;
	t_stack	stack_b;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_num(argv[i]))
			return (1);
		elements[argc - i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (has_duplicates(elements, argc - 1))
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap_init(elements, argc - 1, &stack_a, &stack_b);
	push_swap_sort(&stack_a, &stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}

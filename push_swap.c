/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:39:14 by takitaga          #+#    #+#             */
/*   Updated: 2024/12/30 00:12:10 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_stack(t_stack *a, t_stack *b)
// {
// 	int	i;

// 	i = a->top;
// 	ft_printf("<stack_a>\ntop\n----------\n");
// 	while (i >= 0)
// 	{
// 		ft_printf("%d: %d\n", i, a->stack[i]);
// 		i--;
// 	}
// 	ft_printf("----------\nbottom\n\n");
// 	i = b->top;
// 	ft_printf("<stack_b>\ntop\n----------\n");
// 	while (i >= 0)
// 	{
// 		ft_printf("%d: %d\n", i, b->stack[i]);
// 		i--;
// 	}
// 	ft_printf("----------\nbottom\n\n");
// }

static int	error(void)
{
	ft_putchar_fd('E', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	t_list	ops;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!validate_input(argc, argv))
		return (error());
	if (!init_stack(argc, argv, &a, &b))
		return (error());
	init_ops(&ops);
	sort_stack(&a, &b, &ops);
	optimize_ops(&ops);
	print_ops(&ops);
	free_stack(&a, &b);
	free_ops(&ops);
	return (EXIT_SUCCESS);
}

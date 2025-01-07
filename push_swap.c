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

static int	error(void)
{
	ft_putchar_fd('E', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('\n', 2);
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_list		ops;

	if (argc == 1)
		return (EXIT_SUCCESS);
	if (!validate_input(argc, argv))
		return (error());
	if (!init_stack(argc, argv, &stacks))
		return (error());
	init_ops(&ops);
	sort_stack(&stacks, &ops);
	optimize_ops(&ops);
	print_ops(&ops);
	finalize(&stacks, &ops);
	return (EXIT_SUCCESS);
}

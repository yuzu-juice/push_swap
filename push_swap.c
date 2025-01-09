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
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_list		ops;

	if (argc == 1)
		return (0);
	if (!validate_input(argc, argv))
		return (error());
	if (!init_stack(argc, argv, &stacks))
		return (error());
	init_ops(&ops);
	sort_stack(&stacks, &ops);
	optimize_ops(&ops);
	print_ops(&ops);
	free_stack(&stacks);
	free_ops(&ops);
	return (0);
}

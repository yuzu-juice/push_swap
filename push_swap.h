/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:07:04 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 14:35:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSE 0
# define TRUE 1

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "Libft/libft.h"

typedef struct s_stack {
	int	*stack;
	int	top;
}			t_stack;

void	ft_qsort(int *elements, size_t start, size_t end);
_Bool	has_duplicates(int *elements, int size);
_Bool	is_valid_num(char *num);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
_Bool	is_sorted(t_stack stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
void	sort_more_than_five(t_stack *a, t_stack *b);
int		get_max_index(int *stack, size_t size);
int		get_min_index(int *stack, size_t size);
int		get_largest_number_index_lt(int *stack, size_t size, int target);
int		get_smallest_number_index_gt(int *stack, size_t size, int target);

#endif

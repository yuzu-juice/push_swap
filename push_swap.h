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

typedef enum e_ops
{
	NONE,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_ops;

typedef struct s_stack
{
	int	*stack;
	int	top;
	int	bottom;
}	t_stack;

typedef struct s_list
{
	t_ops			value;
	struct s_list	*next;
}	t_list;

void	ft_qsort(int *elements, size_t start, size_t end);
_Bool	has_duplicates(int *elements, int size);
_Bool	is_valid_num(char *num);
void	sa(t_stack *stack, t_list *ops);
void	sb(t_stack *stack, t_list *ops);
void	ss(t_stack *a, t_stack *b, t_list *ops);
void	pa(t_stack *a, t_stack *b, t_list *ops);
void	pb(t_stack *a, t_stack *b, t_list *ops);
void	papa(t_stack *a, t_stack *b, t_list *ops);
void	pbpb(t_stack *a, t_stack *b, t_list *ops);
void	pa2(t_stack *a, t_stack *b, t_list *ops);
void	pb2(t_stack *a, t_stack *b, t_list *ops);
void	ra(t_stack *a, t_list *ops);
void	rb(t_stack *b, t_list *ops);
void	rr(t_stack *a, t_stack *b, t_list *ops);
void	rra(t_stack *a, t_list *ops);
void	rrb(t_stack *b, t_list *ops);
void	rrr(t_stack *a, t_stack *b, t_list *ops);
_Bool	is_sorted(t_stack stack);
void	sort_a_lte_four(t_stack *a, t_stack *b, t_list *ops);
void	sort_a(t_stack *a, t_stack *b, t_list *ops);
void	sort_b_lte_four(t_stack *a, t_stack *b, t_list *ops);
void	sort_b(t_stack *a, t_stack *b, t_list *ops);
int		get_pivot(int *stack, size_t start, size_t end);
int		get_max_num_index(int *stack, size_t size);
int		get_min_num_index(int *stack, size_t size);
void	split_by_pivot(t_stack *a, t_stack *b, t_list *ops);
int		print_error(void);
void	append_node(t_list *ops, t_ops op);
void	optimize_list(t_list *ops);
void	print_list(t_list *ops);

// delete later
void	print_stack(t_stack *a, t_stack *b, size_t size);

#endif

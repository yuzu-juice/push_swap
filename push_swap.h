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

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_list
{
	t_ops			value;
	struct s_list	*next;
}	t_list;

typedef void	(*t_swap_op)(t_stack*, t_list*);
typedef void	(*t_rot_op)(t_stack*, t_list*);
typedef void	(*t_push_op)(t_stack*, t_stack*, t_list*);

typedef struct s_rot
{
	t_rot_op	forward;
	t_rot_op	reverse;
}	t_rot;

typedef struct s_count
{
	size_t	push;
	size_t	rotate;
}	t_count;

void	pa(t_stack *a, t_stack *b, t_list *ops);
void	pb(t_stack *a, t_stack *b, t_list *ops);
void	ra(t_stack *a, t_list *ops);
void	rb(t_stack *b, t_list *ops);
void	rr(t_stack *a, t_stack *b, t_list *ops);
void	rra(t_stack *a, t_list *ops);
void	rrb(t_stack *b, t_list *ops);
void	rrr(t_stack *a, t_stack *b, t_list *ops);
void	sa(t_stack *a, t_list *ops);
void	sb(t_stack *b, t_list *ops);
void	ss(t_stack *a, t_stack *b, t_list *ops);
_Bool	validate_input(int argc, char *argv[]);
_Bool	init_stack(int argc, char *argv[], t_stack *a, t_stack *b);
void	init_ops(t_list *ops);
_Bool	sort_stack(t_stack *a, t_stack *b, t_list *ops);
void	sort_a(t_stack *a, t_stack *b, t_list *ops);
void	sort_a_lte_three(t_stack *a, t_stack *b, t_list *ops);
void	sort_b(t_stack *a, t_stack *b, t_list *ops);
void	sort_b_lte_three(t_stack *a, t_stack *b, t_list *ops);
void	print_ops(t_list *ops);
void	free_stack(t_stack *a, t_stack *b);
void	free_ops(t_list *ops);
void	append_node(t_list *ops, t_ops op);
int		get_pivot(int *stack, size_t start, size_t end);
_Bool	is_sorted(t_stack *stack, _Bool ascending);
void	split_by_pivot(t_stack *a, t_stack *b, t_list *ops);
int		get_max_num_index(int *stack, size_t size);
int		get_min_num_index(int *stack, size_t size);
void	optimize_ops(t_list *ops);
_Bool	delete_pa_pb(t_list *ops);
_Bool	delete_ra_rra(t_list *ops);
_Bool	delete_rb_rrb(t_list *ops);
_Bool	compress_sa_sb(t_list *ops);
_Bool	compress_ra_pb_rra(t_list *ops);
_Bool	compress_rb_pa_rrb(t_list *ops);
void	push_n_times(t_push_op op, t_stacks *stacks, t_list *ops, size_t n);
void	swap_n_times(t_swap_op op, t_stack *stack, t_list *ops, size_t n);
void	rotate_n_times(t_rot_op op, t_stack *stack, t_list *ops, size_t n);
void	rotate_optimally(t_stack *stack, t_list *ops, t_rot rots, size_t count);

#endif

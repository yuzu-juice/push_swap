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
	t_stack	a;
	t_stack	b;
}	t_stacks;

typedef struct s_list
{
	t_ops			value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef _Bool	(*t_rot_op)(t_stacks*, t_list*);
typedef _Bool	(*t_op)(t_stacks*, t_list*);

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

_Bool	pa(t_stacks *stacks, t_list *ops);
_Bool	pb(t_stacks *stacks, t_list *ops);
_Bool	ra(t_stacks *stacks, t_list *ops);
_Bool	rb(t_stacks *stacks, t_list *ops);
_Bool	rr(t_stacks *stacks, t_list *ops);
_Bool	rra(t_stacks *stacks, t_list *ops);
_Bool	rrb(t_stacks *stacks, t_list *ops);
_Bool	rrr(t_stacks *stacks, t_list *ops);
_Bool	sa(t_stacks *stacks, t_list *ops);
_Bool	sb(t_stacks *stacks, t_list *ops);
_Bool	ss(t_stacks *stacks, t_list *ops);
_Bool	validate_input(int argc, char *argv[]);
_Bool	init_stack(int argc, char *argv[], t_stacks *stacks);
void	init_ops(t_list *ops);
void	sort_stack(t_stacks *stacks, t_list *ops);
void	sort_a(t_stacks *stacks, t_list *ops);
void	sort_a_lte_four(t_stacks *stacks, t_list *ops);
void	sort_a_two(t_stacks *stacks, t_list *ops);
void	sort_a_three(t_stacks *stacks, t_list *ops);
void	sort_a_four(t_stacks *stacks, t_list *ops);
void	sort_b(t_stacks *stacks, t_list *ops);
void	sort_b_lte_three(t_stacks *stacks, t_list *ops);
void	print_ops(t_list *ops);
void	free_stacks(t_stacks *stacks);
void	free_ops(t_list *ops);
void	finalize(t_stacks *stacks, t_list *ops);
void	append_node(t_stacks *stacks, t_list *ops, t_ops op);
void	remove_last_node(t_list *ops);
t_list	*get_last_node(t_list *ops);
t_list	*brute_force_search(t_stacks stacks, size_t size);
int		get_pivot(int *stack, size_t start, size_t end);
int		get_first_quartile(int *stack, size_t start, size_t end);
int		get_third_quartile(int *stack, size_t start, size_t end);
_Bool	is_sorted(t_stack *stack, _Bool ascending);
void	split_by_pivot(t_stacks *stacks, t_list *ops);
int		get_max_num_index(int *stack, size_t size);
int		get_min_num_index(int *stack, size_t size);
void	optimize_ops(t_list *ops);
_Bool	delete_pa_pb(t_list *ops);
_Bool	delete_ra_rra(t_list *ops);
_Bool	delete_rb_rrb(t_list *ops);
_Bool	compress_sa_sb(t_list *ops);
_Bool	compress_ra_rb(t_list *ops);
_Bool	compress_rra_rrb(t_list *ops);
_Bool	compress_ra_pb_rra(t_list *ops);
_Bool	compress_rb_pa_rrb(t_list *ops);
_Bool	compress_sa_any_a_sb(t_list *ops);
_Bool	compress_ra_any_a_rb(t_list *ops);
_Bool	compress_rra_any_a_rrb(t_list *ops);
_Bool	compress_sb_any_b_sa(t_list *ops);
_Bool	compress_rb_any_b_ra(t_list *ops);
_Bool	compress_rrb_any_b_rra(t_list *ops);
_Bool	compress_sa_any_b_sb(t_list *ops);
_Bool	compress_ra_any_b_rb(t_list *ops);
_Bool	compress_rra_any_b_rrb(t_list *ops);
_Bool	compress_sb_any_a_sa(t_list *ops);
_Bool	compress_rb_any_a_ra(t_list *ops);
_Bool	compress_rrb_any_a_rra(t_list *ops);
void	apply_n_times(t_op op, t_stacks *stacks, t_list *ops, size_t n);
void	rotate_a_opt(t_stacks *stacks, t_list *ops, t_rot rots, size_t count);
void	rotate_b_opt(t_stacks *stacks, t_list *ops, t_rot rots, size_t count);

#endif

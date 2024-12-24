#include "../push_swap.h"

void	split_by_pivot(t_stack *a, t_stack *b)
{
	int	pivot;
	int	i;
	int	size;

	size = a->top + 1;

	i = 0;
	pivot = get_pivot(a->stack, 0, a->top);
	while (i < size)
	{
		if (a->stack[a->top] < pivot)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

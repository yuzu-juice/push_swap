#include "../push_swap.h"

int	get_pivot(int *stack, size_t start, size_t end)
{
	int		pivot;
	size_t	size;
	int		*tmp_stack;

	if (end <= start)
		return (-1);
	size = end - start + 1;
	tmp_stack = malloc(sizeof(int) * size);
	if (!tmp_stack)
	{
		free(tmp_stack);
		return (-1);
	}
	ft_memcpy(tmp_stack, stack, sizeof(int) * size);
	ft_qsort(tmp_stack, 0, size - 1);
	pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (pivot);
}

// // cc -Wall -Werror -Wextra get_pivot.c ../Libft/libft.a qsort.c -I ../push_swap.h
// int main(void)
// {
// 	int *stack;
// 	size_t start, end;
//
// 	start = 0;
// 	end = 9;
// 	stack = malloc(sizeof(int) * 10);
// 	stack[0] = 12;
// 	stack[1] = 45;
// 	stack[2] = 7;
// 	stack[3] = 31;
// 	stack[4] = 89;
// 	stack[5] = 24;
// 	stack[6] = 53;
// 	stack[7] = 16;
// 	stack[8] = 72;
// 	stack[9] = 38;

// 	ft_printf("pivot: %i\n", get_pivot(stack, start, end));
// 	free(stack);
// 	return (0);
// }

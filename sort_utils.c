#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	ft_sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_assign_index(t_stack *stack)
{
	int		size;
	int		*arr;
	int		i;
	t_stack	*tmp;

	size = ft_stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		ft_error();
	i = 0;
	tmp = stack;
	while (tmp)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	ft_sort_int_array(arr, size);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == tmp->num)
			{
				tmp->position = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

static int	ft_position_of_max(t_stack *stack)
{
	int	max;
	int	pos;
	int	idx;

	max = stack->position;
	pos = 0;
	idx = 0;
	while (stack)
	{
		if (stack->position > max)
		{
			max = stack->position;
			pos = idx;
		}
		stack = stack->next;
		idx++;
	}
	return (pos);
}

void	ft_move_max_to_top(t_stack **stack_b)
{
	int	size;
	int	pos;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	size = ft_stack_size(*stack_b);
	pos = ft_position_of_max(*stack_b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ft_rb(stack_b);
	}
	else
	{
		while (pos++ < size)
			ft_rrb(stack_b);
	}
}

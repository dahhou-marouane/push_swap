#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		ft_sa(stack_a);
}

void	ft_sort_tree(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	last;

	top = (*stack_a)->num;
	mid = (*stack_a)->next->num;
	last = (*stack_a)->next->next->num;
	if (top < mid && mid > last && top > last)
		ft_rra(stack_a);
	else if (top > mid && mid < last && top > last)
		ft_ra(stack_a);
	else if (top > mid && mid > last && top > last)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (top < mid && mid > last && top < last)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (top > mid && mid < last && top < last)
		ft_sa(stack_a);
}
static int	ft_get_smaller_pos(t_stack **stack)
{
	int	posit;
	int	small;
	t_stack	*tmp;
	int	count;

	tmp = (*stack);
	small = tmp->num;
	posit = 0;
	count = 0;
	while (tmp)
	{
		if (small > tmp->num)
		{
			small = tmp->num;
			posit = count;
		}
		count++;
		tmp = tmp->next;
	}
	return (posit);
}
static void	ft_rotate_to_top(t_stack **stack_a, int posit)
{
	int	size;

	size = ft_size_stack(*stack_a);
	if (posit <= size / 2)
	{
		while (posit > 0)
		{
			ft_ra(stack_a);
			posit--;
		}
	}
	else
	{
		while (posit < size)
		{
			ft_rra(stack_a);
			posit++;	
		}
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	posit;

	posit = ft_get_smaller_pos(stack_a);
	ft_rotate_to_top(stack_a, posit);
	ft_pb(stack_a, stack_b);
	ft_sort_tree(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	posit;

	posit = ft_get_smaller_pos(stack_a);
	ft_rotate_to_top(stack_a, posit);
	ft_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

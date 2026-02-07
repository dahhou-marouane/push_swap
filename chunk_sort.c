#include "push_swap.h"

static void	ft_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->num;
	second = (*stack_a)->next->num;
	third = (*stack_a)->next->next->num;
	if (first > second && second < third && first < third)
		ft_sa(stack_a);
	else if (first > second && second > third)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ft_ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		ft_rra(stack_a);
}

static void	ft_sort_small(t_stack **stack_a)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size == 2 && (*stack_a)->num > (*stack_a)->next->num)
		ft_sa(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk;
	int	target;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_stack_size(*stack_a);
	if (size <= 3)
	{
		ft_sort_small(stack_a);
		return ;
	}
	chunk = 15;
	if (size > 100)
		chunk = 30;
	target = 0;
	while (*stack_a)
	{
		if ((*stack_a)->position <= target)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			target++;
		}
		else if ((*stack_a)->position <= target + chunk)
		{
			ft_pb(stack_a, stack_b);
			target++;
		}
		else
			ft_ra(stack_a);
	}
	while (*stack_b)
	{
		ft_move_max_to_top(stack_b);
		ft_pa(stack_a, stack_b);
	}
}

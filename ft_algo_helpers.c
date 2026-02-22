#include "push_swap.h"

void	ft_set_position(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;

	pos = 0;
	if (!(*stack))
		return ;
	tmp = (*stack);
	while (tmp)
	{
		tmp->position = pos;
		tmp = tmp->next;
		pos++;
	}
}

static void	ft_con_costs(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0)
	{
		ft_ra(stack_a);
		(*cost_a)--;
	}
	while (*cost_b > 0)
	{
		ft_rb(stack_b);
		(*cost_b)--;
	}
}

void	ft_do_costs(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	while ((*cost_a > 0) && (*cost_b > 0))
	{
		ft_rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while ((*cost_a < 0) && (*cost_b < 0))
	{
		ft_rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_a < 0)
	{
		ft_rra(stack_a);
		(*cost_a)++;
	}
	while (*cost_b < 0)
	{
		ft_rrb(stack_b);
		(*cost_b)++;
	}
	ft_con_costs(stack_a, stack_b, cost_a, cost_b);
}

int	ft_minus_to_positive(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_cost_sum(int a, int b)
{
	int	aa;
	int	bb;

	aa = ft_minus_to_positive(a);
	bb = ft_minus_to_positive(b);
	if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
	{
		if (aa > bb)
			return (aa);
		return (bb);
	}
	return (aa + bb);
}

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
void	ft_con_costs(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
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
void	ft_do_costs(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
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
int	ft_cheap_rotate_to_top(t_stack *stack, int size)
{
	int posit;
	int	count;

	count = 0;
	posit = stack->position;
	if (posit <= size / 2)
	{
		while (posit > 0)
		{
			count++;
			posit--;
		}
	}
	else
	{
		while (posit < size)
		{
			count--;
			posit++;	
		}
	}
	return (count);
}
//////////////////////

void	ft_set_cost_a(t_stack **stack)
{
	t_stack	*tmp;
	int 	size;

	tmp = (*stack);
	size = ft_size_stack(*stack);
	while (tmp)
	{
		tmp->cost_a = ft_cheap_rotate_to_top(tmp, size);
		tmp = tmp->next;
	}
}
void	ft_set_cost_b_in_b(t_stack **stack)
{
	t_stack	*tmp;
	int 	size;

	tmp = (*stack);
	size = ft_size_stack(*stack);
	while (tmp)
	{
		tmp->cost_b = ft_cheap_rotate_to_top(tmp, size);
		tmp = tmp->next;
	}
}
void	ft_set_cost_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	while (tmp)
	{
		tmp->cost_b = ft_get_cost_b((*stack_b), tmp->num);
		tmp = tmp->next;
	}
}

int	ft_get_cost_b(t_stack *stack, int num)
{
	int best_val;
	int best_pos;
	int	size_b;
	int	max_val;
	int	max_pos;

	best_val = INT_MIN;
	best_pos = -1;
	max_val = INT_MIN;
	max_pos = 0;
	size_b = ft_size_stack(stack);
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->num > max_val)
		{
			max_val = stack->num;
			max_pos = stack->position;
		}
		if (stack->num < num && stack->num > best_val)
		{
			best_val = stack->num;
			best_pos = stack->position;
		}
		stack = stack->next;
	}
	if (best_pos == -1)
		best_pos = max_pos;
	if (best_pos <= size_b / 2)
		return (best_pos);
	return (best_pos - size_b);
}
void	ft_set_cost_a_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = (*stack_b);
	while (tmp)
	{
		tmp->cost_a = ft_get_cost_a_in_b((*stack_a), tmp->num);
		tmp = tmp->next;
	}
}

int	ft_get_cost_a_in_b(t_stack *stack, int num)
{
	int best_val;
	int best_pos;
	int	size_b;
	int	min_val;
	int	min_pos;

	best_val = INT_MAX;
	best_pos = -1;
	size_b = ft_size_stack(stack);
	min_val = INT_MAX;
	min_pos = 0;
	while (stack)
	{
		if (stack->num < min_val)
		{
			min_val = stack->num;
			min_pos = stack->position;
		}
		if (stack->num > num && stack->num < best_val)
		{
			best_val = stack->num;
			best_pos = stack->position;
		}
		stack = stack->next;
	}
	if (best_pos == -1)
		best_pos = min_pos;
	if (best_pos <= size_b / 2)
		return (best_pos);
	return (best_pos - size_b);
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
int	ft_totale_cost(t_stack *stack)
{
	int	best;
	int	pos;
	int	total;

	pos = -1;
	best = INT_MAX;
	total = 0;
	while (stack)
	{
		total = ft_cost_sum(stack->cost_a, stack->cost_b);
		if (total < best)
		{
			best = total;
			pos = stack->position;
		}
		stack = stack->next;
	}
	return (pos);
}


void	ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int	best_pos;
	int	cost_a;
	int	cost_b;

	tmp = (*stack_a);
	best_pos = -1;
	ft_set_position(stack_a);
	ft_set_position(stack_b);
	ft_set_cost_a(stack_a);
	ft_set_cost_b(stack_a, stack_b);
	best_pos = ft_totale_cost(*stack_a);
	while (tmp && tmp->position != best_pos)
		tmp = tmp->next;
	if (!tmp)
		return ;
	cost_a = tmp->cost_a;
	cost_b = tmp->cost_b;
	ft_do_costs(stack_a, stack_b, &cost_a, &cost_b);
	ft_pb(stack_a, stack_b);
}
/////////////////////
void	ft_move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int	best_pos;
	int	cost_a;
	int	cost_b;

	tmp = (*stack_b);
	best_pos = -1;
	ft_set_position(stack_a);
	ft_set_position(stack_b);
	ft_set_cost_a_in_b(stack_a, stack_b);
	ft_set_cost_b_in_b(stack_b);
	best_pos = ft_totale_cost(*stack_b);
	while (tmp && tmp->position != best_pos)
		tmp = tmp->next;
	if (!tmp)
		return ;
	cost_a = tmp->cost_a;
	cost_b = tmp->cost_b;
	ft_do_costs(stack_a, stack_b, &cost_a, &cost_b);
	ft_pa(stack_a, stack_b);
}

static int	ft_min_pos(t_stack *stack)
{
	int	min_val;
	int	min_pos;

	min_val = INT_MAX;
	min_pos = 0;
	while (stack)
	{
		if (stack->num < min_val)
		{
			min_val = stack->num;
			min_pos = stack->position;
		}
		stack = stack->next;
	}
	return (min_pos);
}

static void	ft_rotate_min_to_top(t_stack **stack_a)
{
	int	size_a;
	int	min_pos;

	ft_set_position(stack_a);
	size_a = ft_size_stack(*stack_a);
	min_pos = ft_min_pos(*stack_a);
	if (min_pos <= size_a / 2)
		while (min_pos-- > 0)
			ft_ra(stack_a);
	else
		while (min_pos++ < size_a)
			ft_rra(stack_a);
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_size_stack(*stack_a) > 3)
		ft_move_a_to_b(stack_a, stack_b);
	ft_sort_tree(stack_a);
	while (*stack_b)
		ft_move_b_to_a(stack_a, stack_b);
	ft_rotate_min_to_top(stack_a);
}

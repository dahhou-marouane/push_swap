
#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_size_stack(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
/////////////
// void	ft_set_cost_a(t_stack **stack)
// {
// 	t_stack	*tmp;
// 	int size = ft_size_stack(*stack);
// 	tmp = (*stack);
// 	while (tmp)
// 	{
// 		tmp->cost_a = ft_cheap_rotate_to_top(tmp, size);
// 		tmp = tmp->next;
// 	}
// }
// void	ft_set_cost_b(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*tmp;
// 	t_stack	*tmp2;

// 	tmp = (*stack_a);
// 	tmp2 = (*stack_b);
// 	if (!(*stack_a) || !(*stack_b))
// 	{
// 		while (tmp)
// 		{
// 			tmp->cost_b = 0;
// 			tmp = tmp->next;
// 		}
// 	}
// 	while (tmp)
// 	{
// 		tmp->cost_b = ft_get_cost_b(tmp2, tmp->num);
// 		tmp = tmp->next;
// 		tmp2 = tmp2->next;
// 	}
// 	tmp = (*stack_a);	
// }

// int	ft_get_cost_b(t_stack *stack, int num)
// {
// 	int best_val;
// 	int best_pos;
// 	int	size_b;

// 	best_val = INT_MAX;
// 	best_pos = -1;
// 	size_b = ft_size_stack(stack);
// 	while (stack)
// 	{
// 		if (stack->num < num && stack->num > best_val)
// 		{
// 			best_val = stack->num;
// 			best_pos = stack->position;
// 		}
// 		stack = stack->next;
// 	}
// 	if (best_pos <= size_b / 2)
// 		return (best_pos);
// 	return (best_pos - size_b);
// }


// void	ft_algo(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack *tmp;
// 	int		best;

// 	tmp = (*stack_a);
// 	ft_set_position(stack_a);
// 	ft_set_position(stack_b);
// 	ft_set_cost_a(stack_a);
// 	ft_set_cost_b(stack_a, stack_b);
// 	while (tmp)
// 		tmp = tmp->next;
// 	tmp = (*stack_a);
// 	best = tmp->num;
// 	while (tmp)
// 	{
// 		if (tmp->cost_a < tmp->next->cost_a)
// 			best = tmp->num;
// 		tmp = tmp->next;
// 	}
// }


//////////////
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_size_stack(*stack_a);
	
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_tree(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a , stack_b);
	else
		ft_algo(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	char	**arn;
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)stack_b;
	if (ac == 1)
		return (0);
	arn = ft_parsing(ac, av);
	ft_check_num(arn);
	stack_a = ft_fill_stack(arn);
	ft_free_split(arn);
	stack_b = NULL;
	if (ft_is_sorted(stack_a))
	{
		/// need to check the stack_b is it sorted need to do 
		// if (!stack_b) and after free ing 
		ft_free_stack(&stack_a);
		return (0);
	}
	else
	{
		ft_sort_stack(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	return (0);
}

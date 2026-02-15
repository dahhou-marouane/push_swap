#include "push_swap_bonus.h"

int	ft_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	if (stack_b)
		return (0);
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

int	main(int ac, char **av)
{
	char	**arn;
	t_stack	*stack_a;

	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	arn = ft_parsing(ac, av);
	if (!arn)
		exit(1);
	ft_check_num(arn);
	stack_a = ft_fill_stack(arn);
	ft_free_split(arn);
	if (!stack_a)
		exit(1);
	stack_b = NULL;
	ft_algo_moves(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a, stack_b))
		ft_success(1);
	else
		ft_success(0);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

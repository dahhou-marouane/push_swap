/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 01:53:27 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 01:53:28 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_sort_five(stack_a, stack_b);
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
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		return (0);
	}
	else
		ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

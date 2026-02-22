/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 01:51:09 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 01:51:10 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cheap_rotate_to_top(t_stack *stack, int size)
{
	int	posit;
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

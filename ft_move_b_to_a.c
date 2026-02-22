/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 01:52:25 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 01:59:42 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		best_pos;
	int		cost_a;
	int		cost_b;

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

void	ft_set_cost_a_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = (*stack_b);
	while (tmp)
	{
		tmp->cost_a = ft_get_cost_a_in_b((*stack_a), tmp->num, INT_MAX,
				INT_MAX);
		tmp = tmp->next;
	}
}

int	ft_get_cost_a_in_b(t_stack *stack, int num, int best_val, int min_val)
{
	int	best_pos;
	int	size_b;
	int	min_pos;

	best_pos = -1;
	size_b = ft_size_stack(stack);
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
	return (ft_best_pos(best_pos, size_b));
}

int	ft_best_pos(int best_pos, int size_b)
{
	if (best_pos <= size_b / 2)
		return (best_pos);
	return (best_pos - size_b);
}

void	ft_set_cost_b_in_b(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	tmp = (*stack);
	size = ft_size_stack(*stack);
	while (tmp)
	{
		tmp->cost_b = ft_cheap_rotate_to_top(tmp, size);
		tmp = tmp->next;
	}
}

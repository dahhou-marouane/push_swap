/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 01:50:25 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 01:59:10 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		best_pos;
	int		cost_a;
	int		cost_b;

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

void	ft_set_cost_a(t_stack **stack)
{
	t_stack	*tmp;
	int		size;

	tmp = (*stack);
	size = ft_size_stack(*stack);
	while (tmp)
	{
		tmp->cost_a = ft_cheap_rotate_to_top(tmp, size);
		tmp = tmp->next;
	}
}

void	ft_set_cost_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	while (tmp)
	{
		if (*stack_b)
			tmp->cost_b = ft_get_cost_b((*stack_b), tmp->num, -1, -1);
		else
			tmp->cost_b = 0;
		tmp = tmp->next;
	}
}

int	ft_get_cost_b(t_stack *stack, int num, int best_val, int max_val)
{
	int	best_pos;
	int	size_b;
	int	max_pos;

	best_pos = -1;
	max_pos = 0;
	size_b = ft_size_stack(stack);
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
	return (ft_best_pos(best_pos, size_b));
}

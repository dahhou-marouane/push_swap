/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:21 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:17:36 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

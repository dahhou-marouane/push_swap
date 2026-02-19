/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:34 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:07:35 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = head;
	head->next = NULL;
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = head;
	head->next = NULL;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}

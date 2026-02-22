/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:08:12 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 00:16:40 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*sec;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = (*stack_a);
	sec = (*stack_a)->next;
	head->next = sec->next;
	sec->next = head;
	(*stack_a) = sec;
	write(1, "sa\n", 3);
}

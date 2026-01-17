/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:22:55 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/09 11:05:09 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_node(t_stack **stack, int num)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (-1);
	node->next = NULL;
	node->num = num;
	node->num_index = 0;
	while ((*stack))
	{
		(*stack) = (*stack)->next;
	}
	
	node->prev = *stack;
	return (0);
}
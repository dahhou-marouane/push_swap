/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:47 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 00:04:20 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->cost_a = 0;
	node->cost_b = 0;
	node->position = 0;
	node->next = NULL;
	return (node);
}

int	ft_has_duplicate(t_stack *stack)
{
	t_stack	*curent;
	t_stack	*against;

	curent = stack;
	while (curent)
	{
		against = curent->next;
		while (against)
		{
			if (curent->num == against->num)
				return (1);
			against = against->next;
		}
		curent = curent->next;
	}
	return (0);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
	*stack = NULL;
}

t_stack	*ft_fill_stack(char **arn)
{
	size_t	i;
	t_stack	*new;
	t_stack	*stack;
	int		error;

	stack = NULL;
	i = 0;
	error = 0;
	while (arn[i])
	{
		new = ft_new_node(ft_atoi(arn[i], &error));
		if (!new)
			ft_error_stack(arn, &stack);
		ft_add_back(&stack, new);
		i++;
	}
	if (ft_has_duplicate(stack))
		ft_error_stack(arn, &stack);
	if (stack)
		ft_change_num_to_idx(&stack);
	return (stack);
}

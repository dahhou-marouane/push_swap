/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 06:30:00 by one               #+#    #+#             */
/*   Updated: 2026/02/02 06:30:00 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->n = n;
	node->i = 0;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
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
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_has_duplicate(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->n == check->n)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

t_stack	*ft_fill_stack(char **arn)
{
	t_stack	*stack;
	int		i;
	int		num;

	stack = NULL;
	i = 0;
	while (arn[i])
	{
		num = ft_atoi(arn[i]);
		ft_add_back(&stack, ft_new_node(num));
		i++;
	}
	if (ft_has_duplicate(stack))
	{
		ft_free_stack(&stack);
		ft_error();
	}
	return (stack);
}

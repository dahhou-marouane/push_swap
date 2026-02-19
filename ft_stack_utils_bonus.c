/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:45 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:07:46 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_stack	*ft_new_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

static int	ft_has_duplicate(t_stack *stack)
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
		{
			ft_free_stack(&stack);
			ft_free_split(arn);
			return (NULL);
		}
		ft_add_back(&stack, new);
		i++;
	}
	if (ft_has_duplicate(stack))
		ft_error_stack(arn, &stack);
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:50 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:11:50 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_stack_moves	*ft_new_node_moves(char *move)
{
	t_stack_moves	*node;

	node = malloc(sizeof(t_stack_moves));
	if (!node)
		return (NULL);
	node->operation = move;
	node->next = NULL;
	return (node);
}

void	ft_free_stack_moves(t_stack_moves **stack)
{
	t_stack_moves	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->operation);
		free(*stack);
		(*stack) = tmp;
	}
	*stack = NULL;
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_add_back_moves(t_stack_moves **stack, t_stack_moves *new)
{
	t_stack_moves	*tmp;

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

int	ft_fill_stack_moves(t_stack_moves **stack, char *move)
{
	t_stack_moves	*new;

	new = ft_new_node_moves(move);
	if (!new)
	{
		return (0);
	}
	ft_add_back_moves(stack, new);
	return (1);
}

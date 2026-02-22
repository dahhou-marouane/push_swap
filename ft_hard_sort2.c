/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_sort2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:17:07 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/20 23:40:20 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_smaller_pos(t_stack **stack)
{
	int		posit;
	int		small;
	t_stack	*tmp;
	int		count;

	tmp = (*stack);
	small = tmp->num;
	posit = 0;
	count = 0;
	while (tmp)
	{
		if (small > tmp->num)
		{
			small = tmp->num;
			posit = count;
		}
		count++;
		tmp = tmp->next;
	}
	return (posit);
}

void	ft_rotate_to_top(t_stack **stack_a, int posit)
{
	int	size;

	size = ft_size_stack(*stack_a);
	if (posit <= size / 2)
	{
		while (posit > 0)
		{
			ft_ra(stack_a);
			posit--;
		}
	}
	else
	{
		while (posit < size)
		{
			ft_rra(stack_a);
			posit++;
		}
	}
}

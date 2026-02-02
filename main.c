/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:31:57 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/27 03:36:22 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int ac, char **av)
{
	char	**arn;
	t_stack	*stack_a;
	t_stack	*tmp;

	if (ac == 1)
		return (0);
	arn = ft_parsing(ac, av);
	stack_a = ft_fill_stack(arn);
	ft_free_split(arn);
	tmp = stack_a;
	while (tmp)
	{
		printf("Number: %d\n", tmp->n);
		tmp = tmp->next;
	}
	ft_free_stack(&stack_a);
	return (0);
}

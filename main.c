/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:31:57 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/07 18:11:40 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_num(char **arn)
{
	int i;
	int error;

	i = 0;
	error = 0;
	while (arn[i])
	{
		ft_atoi(arn[i], &error);
		if (error)
		{
			ft_free_split(arn);
			ft_error();
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	**arn;
	t_stack	*stack_a;
	t_stack	*tmp;

	if (ac == 1)
		return (0);
	arn = ft_parsing(ac, av);
	ft_check_num(arn);
	stack_a = ft_fill_stack(arn);
	ft_free_split(arn);
	tmp = stack_a;
	while (tmp)
	{
		printf("Number: [%d]\n", tmp->num);
		tmp = tmp->next;
	}
	ft_free_stack(&stack_a);
	return (0);
}

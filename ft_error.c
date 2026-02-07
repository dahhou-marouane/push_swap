/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:13:08 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/06 21:45:08 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void	ft_error_stack(char **arn, t_stack **stack)
{
	ft_free_stack(stack);
	ft_free_split(arn);
	ft_error();
}

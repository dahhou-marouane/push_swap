/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:35:52 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/17 11:32:08 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_space(char c)
{
	if (c >= '0' && c <= '9' || c == ' ')
		return (1);
	return (0);
}

void	check_orth(int ac, char *av[])
{
	size_t	j;
	size_t	i;

	j = 2;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if(!ft_isdigit_space(av[j][i]))
				ft_error();
			i++;
		}
		j++;
	}
}
void	organize(int ac, char **av)
{
	size_t		i;
	char	**a;

	i = 2;
	check_orth(ac, **av);
	while (i < ac)
	{
		a = ft_split(av[i], ' ');
		
		ft_freei(a, ft_cw(av[i], ' '));
		i++;
	}
	
}

int	main(int ac, char *av[])
{
	size_t	i;

	organize(ac, **av);
	while ()
	{
		
	}
	a = ft_split(av[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:49:46 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/27 04:15:42 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_spacestr(char *av)
{
	int		i;
	size_t	j;

	j = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			j++;
		i++;
	}
	if (j == ft_strlen(av))
		ft_error();
}

void	ft_emptystr(char *av)
{
	if (!av || av[0] == '\0')
		ft_error();
}

int	ft_validstr(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ')
			i++;
		if (av[i] == '\0')
			break ;
		if (av[i] == '-' || av[i] == '+')
			i++;
		if (!ft_isdigit(av[i]))
			return (0);
		while (ft_isdigit(av[i]))
			i++;
		if (av[i] != ' ' && av[i] != '\0')
			return (0);
	}
	return (1);
}

char	**ft_parsing(int ac, char **av)
{
	int		j;
	char	*alln;
	char	**arn;

	j = 1;
	alln = NULL;
	while (j < ac)
	{
		ft_emptystr(av[j]);
		ft_spacestr(av[j]);
		if (!ft_validstr(av[j]))
			ft_error();
		j++;
	}
	j = 1;
	while (j < ac)
	{
		alln = ft_strjoin(alln, av[j]);
		j++;
	}
	arn = ft_split(alln, ' ');
	free(alln);
	return (arn);
}

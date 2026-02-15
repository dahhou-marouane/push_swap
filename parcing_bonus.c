#include "push_swap_bonus.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	ft_spacestr(char *av)
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

static void	ft_emptystr(char *av)
{
	if (!av || av[0] == '\0')
		ft_error();
}

static int	ft_validstr(char *av)
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
		if (!alln)
			exit(1);
		j++;
	}
	arn = ft_split(alln, ' ');
	free(alln);
	return (arn);
}

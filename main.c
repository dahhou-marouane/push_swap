
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
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	arn = ft_parsing(ac, av);
	ft_check_num(arn);
	stack_a = ft_fill_stack(arn);
	ft_free_split(arn);
	stack_b = NULL;
	if (ft_is_sorted(stack_a))
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	ft_assign_index(stack_a);
	ft_chunk_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void	ft_error_stack(char **ar, t_stack **stack)
{
	ft_free_stack(stack);
	ft_free_split(ar);
	ft_error();
}

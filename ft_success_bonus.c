#include "push_swap_bonus.h"

void	ft_success(int i)
{
	if (i == 1)
		write(1, "OK\n", 3);
	else if (i == 0)
		write(1, "KO\n", 3);
}

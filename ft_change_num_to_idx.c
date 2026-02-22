#include "push_swap.h"

void	ft_change_num_to_idx(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		count;

	tmp = (*stack);
	while (tmp)
	{
		count = 0;
		tmp2 = (*stack);
		while (tmp2)
		{
			if (tmp->num > tmp2->num)
				count++;
			tmp2 = tmp2->next;
		}
		tmp->idx = count;
		tmp = tmp->next;
	}
	tmp = (*stack);
	while (tmp)
	{
		tmp->num = tmp->idx;
		tmp = tmp->next;
	}
}

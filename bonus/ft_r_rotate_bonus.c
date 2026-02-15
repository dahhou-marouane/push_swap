#include "push_swap_bonus.h"

void	ft_rra(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	prev = *stack_a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	prev = *stack_b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}

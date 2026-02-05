#include "push_swap.h"

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next || !*stack_a || !(*stack_a)->next)
        return ;
	prev = *stack_a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	prev = *stack_b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrr\n", 4);
}

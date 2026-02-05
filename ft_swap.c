#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*sec;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = (*stack_a);
	sec = (*stack_a)->next;
	head->next = sec->next;
	sec->next = head;
	(*stack_a) = sec;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*sec;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = (*stack_b);
	sec = (*stack_b)->next;
	head->next = sec->next;
	sec->next = head;
	(*stack_b) = sec;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*sec;

	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	head = (*stack_a);
	sec = (*stack_a)->next;
	head->next = sec->next;
	sec->next = head;
	head = (*stack_b);
	sec = (*stack_b)->next;
	head->next = sec->next;
	sec->next = head;
	write(1, "ss\n", 3);
}

#include "push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*head;
    t_stack	*last;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    head = *stack_a;         
    *stack_a = (*stack_a)->next;   
    last = *stack_a;
    while (last->next)             
		last = last->next;
    last->next = head;
    head->next = NULL;
    write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*head;
    t_stack	*last;

    if (!*stack_b || !(*stack_b)->next)
        return ;
    head = *stack_b;    
    *stack_b = (*stack_b)->next;   
    last = *stack_b;
    while (last->next)             
		last = last->next;
    last->next = head;
    head->next = NULL;
    write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
    t_stack	*last;

	if (!*stack_b || !(*stack_b)->next || !*stack_a || !(*stack_a)->next)
        return ;
    head = *stack_a;         
    *stack_a = (*stack_a)->next;   
    last = *stack_a;
    while (last->next)             
		last = last->next;
    last->next = head;
    head->next = NULL;
	head = *stack_b;    
    *stack_b = (*stack_b)->next;   
    last = *stack_b;
    while (last->next)             
		last = last->next;
    last->next = head;
    head->next = NULL;
    write(1, "rr\n", 3);
}

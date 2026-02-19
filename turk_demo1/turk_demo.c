#include "turk_demo.h"

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

/* ======================== Basic Node Helpers ======================== */

static void	fail_alloc(void)
{
	exit(1);
}

t_node	*turk_node_new(int idx)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (!node)
		fail_alloc();
	node->idx = idx;
	node->pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	turk_node_push_back(t_node **stack, t_node *new_node)
{
	t_node	*last;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	turk_node_free(t_node **stack)
{
	t_node	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

/* ======================== Small Utilities ======================== */

static void	print_op(const char *op)
{
	int	len;

	len = 0;
	while (op[len])
		len++;
	write(1, op, len);
	write(1, "\n", 1);
}

static int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->idx > a->next->idx)
			return (0);
		a = a->next;
	}
	return (1);
}

static t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	set_positions(t_node *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

static int	min_idx_pos(t_node *stack)
{
	int	min_idx;
	int	min_pos;

	min_idx = INT_MAX;
	min_pos = 0;
	while (stack)
	{
		if (stack->idx < min_idx)
		{
			min_idx = stack->idx;
			min_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (min_pos);
}

static int	max_idx_pos(t_node *stack)
{
	int	max_idx;
	int	max_pos;

	max_idx = INT_MIN;
	max_pos = 0;
	while (stack)
	{
		if (stack->idx > max_idx)
		{
			max_idx = stack->idx;
			max_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (max_pos);
}

static int	cost_from_pos(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

/* ======================== Primitive Operations ======================== */

static void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	print_op("sa");
}

static void	pa(t_node **a, t_node **b)
{
	t_node	*top_b;

	if (!*b)
		return ;
	top_b = *b;
	*b = (*b)->next;
	top_b->next = *a;
	*a = top_b;
	print_op("pa");
}

static void	pb(t_node **a, t_node **b)
{
	t_node	*top_a;

	if (!*a)
		return ;
	top_a = *a;
	*a = (*a)->next;
	top_a->next = *b;
	*b = top_a;
	print_op("pb");
}

static void	ra(t_node **a)
{
	t_node	*top;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	top = *a;
	*a = (*a)->next;
	last = last_node(*a);
	last->next = top;
	top->next = NULL;
	print_op("ra");
}

static void	rb(t_node **b)
{
	t_node	*top;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	top = *b;
	*b = (*b)->next;
	last = last_node(*b);
	last->next = top;
	top->next = NULL;
	print_op("rb");
}

static void	rr(t_node **a, t_node **b)
{
	t_node	*top_a;
	t_node	*top_b;
	t_node	*last_a;
	t_node	*last_b;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	top_a = *a;
	top_b = *b;
	*a = (*a)->next;
	*b = (*b)->next;
	last_a = last_node(*a);
	last_b = last_node(*b);
	last_a->next = top_a;
	last_b->next = top_b;
	top_a->next = NULL;
	top_b->next = NULL;
	print_op("rr");
}

static void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	print_op("rra");
}

static void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
	print_op("rrb");
}

static void	rrr(t_node **a, t_node **b)
{
	t_node	*prev_a;
	t_node	*last_a;
	t_node	*prev_b;
	t_node	*last_b;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	prev_a = *a;
	while (prev_a->next->next)
		prev_a = prev_a->next;
	last_a = prev_a->next;
	prev_a->next = NULL;
	last_a->next = *a;
	*a = last_a;
	prev_b = *b;
	while (prev_b->next->next)
		prev_b = prev_b->next;
	last_b = prev_b->next;
	prev_b->next = NULL;
	last_b->next = *b;
	*b = last_b;
	print_op("rrr");
}

/* ======================== Target & Cost Computation ======================== */

/* For pushing from B to A: find smallest idx in A that is > b_idx. */
static int	target_pos_in_a(t_node *a, int b_idx)
{
	t_node	*cur;
	int	best_idx;
	int	best_pos;

	cur = a;
	best_idx = INT_MAX;
	best_pos = -1;
	while (cur)
	{
		if (cur->idx > b_idx && cur->idx < best_idx)
		{
			best_idx = cur->idx;
			best_pos = cur->pos;
		}
		cur = cur->next;
	}
	if (best_pos != -1)
		return (best_pos);
	return (min_idx_pos(a));
}

/* For pushing from A to B: find largest idx in B that is < a_idx. */
static int	target_pos_in_b(t_node *b, int a_idx)
{
	t_node	*cur;
	int	best_idx;
	int	best_pos;

	cur = b;
	best_idx = INT_MIN;
	best_pos = -1;
	while (cur)
	{
		if (cur->idx < a_idx && cur->idx > best_idx)
		{
			best_idx = cur->idx;
			best_pos = cur->pos;
		}
		cur = cur->next;
	}
	if (best_pos != -1)
		return (best_pos);
	return (max_idx_pos(b));
}

static void	set_costs_a_to_b(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;
	int	target_pos;

	set_positions(a);
	set_positions(b);
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (!b)
			target_pos = 0;
		else
			target_pos = target_pos_in_b(b, a->idx);
		a->cost_a = cost_from_pos(a->pos, size_a);
		a->cost_b = cost_from_pos(target_pos, size_b);
		a = a->next;
	}
}

static void	set_costs_b_to_a(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;
	int	target_pos;

	set_positions(a);
	set_positions(b);
	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		target_pos = target_pos_in_a(a, b->idx);
		b->cost_a = cost_from_pos(target_pos, size_a);
		b->cost_b = cost_from_pos(b->pos, size_b);
		b = b->next;
	}
}

static int	total_cost(int cost_a, int cost_b)
{
	int	a;
	int	b;

	a = abs_int(cost_a);
	b = abs_int(cost_b);
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
	{
		if (a > b)
			return (a);
		return (b);
	}
	return (a + b);
}

static t_node	*cheapest_node(t_node *stack)
{
	t_node	*best;
	int	best_cost;
	int	cur_cost;

	best = stack;
	best_cost = total_cost(stack->cost_a, stack->cost_b);
	stack = stack->next;
	while (stack)
	{
		cur_cost = total_cost(stack->cost_a, stack->cost_b);
		if (cur_cost < best_cost)
		{
			best = stack;
			best_cost = cur_cost;
		}
		stack = stack->next;
	}
	return (best);
}

/* ======================== Move Execution ======================== */

static void	apply_costs(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

static void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	if (is_sorted(*a))
		return ;
	x = (*a)->idx;
	y = (*a)->next->idx;
	z = (*a)->next->next->idx;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else
		rra(a);
}

static void	move_best_a_to_b(t_node **a, t_node **b)
{
	t_node	*best;
	int	cost_a;
	int	cost_b;

	set_costs_a_to_b(*a, *b);
	best = cheapest_node(*a);
	cost_a = best->cost_a;
	cost_b = best->cost_b;
	apply_costs(a, b, &cost_a, &cost_b);
	pb(a, b);
}

static void	move_best_b_to_a(t_node **a, t_node **b)
{
	t_node	*best;
	int	cost_a;
	int	cost_b;

	set_costs_b_to_a(*a, *b);
	best = cheapest_node(*b);
	cost_a = best->cost_a;
	cost_b = best->cost_b;
	apply_costs(a, b, &cost_a, &cost_b);
	pa(a, b);
}

static void	rotate_min_to_top(t_node **a)
{
	int	min_pos;
	int	size;

	set_positions(*a);
	min_pos = min_idx_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
}

/* ======================== Public Algorithm ======================== */

void	turk_sort(t_node **a, t_node **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		sa(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	pb(a, b);
	if (stack_size(*a) > 3)
		pb(a, b);
	while (stack_size(*a) > 3)
		move_best_a_to_b(a, b);
	sort_three(a);
	while (*b)
		move_best_b_to_a(a, b);
	rotate_min_to_top(a);
}

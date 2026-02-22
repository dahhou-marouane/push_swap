/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:07:11 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/22 01:19:30 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_do_moves(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		ft_sa(stack_a);
	else if (ft_strcmp(op, "sb\n") == 0)
		ft_sb(stack_b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(op, "pa\n") == 0)
		ft_pa(stack_a, stack_b);
	else if (ft_strcmp(op, "pb\n") == 0)
		ft_pb(stack_a, stack_b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ft_ra(stack_a);
	else if (ft_strcmp(op, "rb\n") == 0)
		ft_rb(stack_b);
	else if (ft_strcmp(op, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(op, "rra\n") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		ft_rrb(stack_b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
}

int	ft_is_valid_move(char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		return (1);
	if (ft_strcmp(op, "sb\n") == 0)
		return (1);
	if (ft_strcmp(op, "ss\n") == 0)
		return (1);
	if (ft_strcmp(op, "pa\n") == 0)
		return (1);
	if (ft_strcmp(op, "pb\n") == 0)
		return (1);
	if (ft_strcmp(op, "ra\n") == 0)
		return (1);
	if (ft_strcmp(op, "rb\n") == 0)
		return (1);
	if (ft_strcmp(op, "rr\n") == 0)
		return (1);
	if (ft_strcmp(op, "rra\n") == 0)
		return (1);
	if (ft_strcmp(op, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(op, "rrr\n") == 0)
		return (1);
	return (0);
}

static int	ft_push_move_or_fail(t_stack_moves **stack_moves, char *move)
{
	if (!ft_is_valid_move(move))
	{
		free(move);
		ft_free_stack_moves(stack_moves);
		return (0);
	}
	if (!ft_fill_stack_moves(stack_moves, move))
	{
		free(move);
		ft_free_stack_moves(stack_moves);
		return (0);
	}
	return (1);
}

int	ft_read_moves(t_stack_moves **stack_moves)
{
	int		gnl_error;
	char	*move;

	gnl_error = 0;
	*stack_moves = NULL;
	move = get_next_line(0, &gnl_error);
	while (move)
	{
		if (gnl_error)
		{
			free(move);
			ft_free_stack_moves(stack_moves);
			return (0);
		}
		if (!ft_push_move_or_fail(stack_moves, move))
			return (0);
	}
	if (gnl_error)
	{
		ft_free_stack_moves(stack_moves);
		return (0);
	}
	return (1);
}

void	ft_algo_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack_moves	*stack_moves;
	t_stack_moves	*tmp_moves;

	stack_moves = NULL;
	if (!ft_read_moves(&stack_moves))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		ft_error();
	}
	tmp_moves = stack_moves;
	while (tmp_moves)
	{
		ft_do_moves(stack_a, stack_b, tmp_moves->operation);
		tmp_moves = tmp_moves->next;
	}
	ft_free_stack_moves(&stack_moves);
}

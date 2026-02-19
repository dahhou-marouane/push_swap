/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:08:39 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:13:57 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}				t_stack;

//  parcing
void	ft_emptystr(char *av);
int		ft_validstr(char *av);
char	**ft_split(char *s, char c);
char	**ft_parsing(int ac, char **av);
void	ft_spacestr(char *av);
void	ft_error(void);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *str, int *error);
void	ft_free_split(char **arr);
void	ft_check_num(char **arn);

// stack functions
t_stack	*ft_new_node(int n);
void	ft_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_fill_stack(char **arn);
void	ft_free_stack(t_stack **stack);
int		ft_has_duplicate(t_stack *stack);
void	ft_error_stack(char **arn, t_stack **stack);
int		ft_size_stack(t_stack *stack);

// hard code sort
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_tree(t_stack **stack_a);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

// stack operations
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

// algo
int		ft_cheap_rotate_to_top(t_stack *stack, int size);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_set_cost_a(t_stack **stack);
void	ft_set_cost_a_in_b(t_stack **stack_a, t_stack **stack_b);
void	ft_set_cost_b(t_stack **stack_a, t_stack **stack_b);
void	ft_set_cost_b_in_b(t_stack **stack);
int		ft_get_cost_b(t_stack *stack, int num);
int		ft_get_cost_a_in_b(t_stack *stack, int num);
int		ft_minus_to_positive(int n);
int		ft_cost_sum(int a, int b);
void	ft_set_position(t_stack **stack);
int		ft_totale_cost(t_stack *stack);
void	ft_con_costs(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	ft_do_costs(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	ft_move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	ft_move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	ft_algo(t_stack **stack_a, t_stack **stack_b);

#endif

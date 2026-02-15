#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				i;
	int				position;
	struct s_stack	*next;
}	t_stack;

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
t_stack	*ft_new_node(int n, int i);
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

// sorting


#endif

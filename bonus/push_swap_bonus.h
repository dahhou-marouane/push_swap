#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_moves
{
	char					*operation;
	struct s_stack_moves	*next;
}	t_stack_moves;


// get_next_line
# define BUFFER_SIZE 1

char	*get_next_line(int fd, int *error);
char	*ft_strjoin_get(char *s1, char *s2);
char	*ft_read_buffer_get(int fd, char **store, int *error);
char	*ft_strchr_get(char *s, char c);
char	*ft_line_get(char *s);
void	ft_strlcat_get(char *dst, char *src, size_t dstsize);
char	*ft_store_get(char *s, int *error);
void	ft_free_gnl(char **store, char *buffer);
char	*ft_set_gnl_error(int *error, int value);

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

// stack functions
void	ft_success(int i);
void	ft_do_moves(t_stack **stack_a, t_stack **stack_b, char *op);
void    ft_free_stack(t_stack **stack);
void	ft_error_stack(char **ar, t_stack **stack);
void	ft_error(void);
int		ft_is_valid_move(char *op);
int		ft_strcmp(char *s1, char *s2);
void	ft_add_back_moves(t_stack_moves **stack, t_stack_moves *new);
void    ft_free_stack_moves(t_stack_moves **stack);
void	ft_add_back(t_stack **stack, t_stack *new);
int		ft_read_moves(t_stack_moves **stack_moves);
void	ft_algo_moves(t_stack **stack_a, t_stack **stack_b);
// parcing
size_t	ft_strlen(char *s);
int		ft_atoi(char *str, int *error);
void	ft_check_num(char **arn);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_parsing(int ac, char **av);
t_stack *ft_fill_stack(char **arn);
char	**ft_split(char *s, char c);
void	 ft_free_split(char **arr);
int		ft_has_false_move(t_stack_moves *stack);
int		ft_fill_stack_moves(t_stack_moves **stack, char *move);
#endif

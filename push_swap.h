/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:53:26 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/03 12:04:34 by one              ###   ########.fr       */
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
	int				n;
	int				i;
	struct s_stack	*next;
}	t_stack;

void	ft_emptystr(char *av);
int		ft_validstr(char *av);
char	**ft_split(char *s, char c);
char	**ft_parsing(int ac, char **av);
void	ft_spacestr(char *av);
void	ft_error(void);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(char *str);

// Stack functions
t_stack	*ft_new_node(int n);
void	ft_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_fill_stack(char **arn);
void	ft_free_stack(t_stack **stack);
int		ft_has_duplicate(t_stack *stack);

#endif

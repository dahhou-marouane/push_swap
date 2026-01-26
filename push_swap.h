/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:53:26 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/26 22:32:59 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				n;
	int				i;
	struct s_stack	*next;
}	t_stack;

void	ft_emptystr(char *av);
int		ft_validstr(char *av);
char	*ft_parsing(int ac, char **av);
void	ft_spacestr(char *av);
void	ft_error(void);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);

#endif

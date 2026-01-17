/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:36:58 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/17 11:36:33 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
# include <limits.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_stack {
	int		myNum;
	char	myLetter;
	t_stack	*next;
}				t_stack;

char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *s);
void	*ft_freei(char **a, size_t i);
size_t	ft_cw(char const *s, char c);
void	ft_error(void);
int	ft_atoi(const char *str);
int	ft_isdigit_space(char c);
#endif
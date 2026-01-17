/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:36:58 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/09 10:24:17 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *s);

typedef struct s_stack
{
	struct s_stack* next;
	struct s_stack* prev;
	
	int num;
	int num_index;

} t_stack;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 02:53:26 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/25 06:10:57 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_emptystr(char *av);
int	ft_validstr(char *av);
void	ft_parsing(int ac, char **av);
void	ft_spacestr(char *av);
void	ft_error(void);
int		ft_isdigit(int c);


#endif

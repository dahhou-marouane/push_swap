/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:16:11 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/26 22:33:25 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_cat(char *p, char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;

	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!p)
		return (NULL);
	ft_cat(p, s1);
	if (s1)
		p[ft_strlen(p)]= ' ';
	ft_cat(p + ft_strlen(p), s2);
	if (s1)
		free(s1);
	return (p);
}

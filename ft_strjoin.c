/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:16:11 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/04 23:00:25 by one              ###   ########.fr       */
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
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(len1 + len2 + 2);
	if (!p)
	{
		if (s1)
			free(s1);
		exit(1);
	}
	ft_cat(p, s1);
	if (s1)
	{
		p[len1] = ' ';
		p[len1 + 1] = '\0';
	}
	ft_cat(p + ft_strlen(p), s2);
	if (s1)
		free(s1);
	return (p);
}

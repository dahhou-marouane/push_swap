/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:08:17 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/19 20:08:18 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_strlcat_get(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!src)
		return ;
	if (!dst && dstsize == 0)
		return ;
	i = ft_strlen(dst);
	if (i >= dstsize)
		return ;
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
}

char	*ft_strchr_get(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(size);
	if (!p)
	{
		free(s1);
		return (NULL);
	}
	p[0] = '\0';
	ft_strlcat_get(p, s1, size);
	ft_strlcat_get(p, s2, size);
	free(s1);
	return (p);
}

void	ft_free_gnl(char **store, char *buffer)
{
	free(*store);
	*store = NULL;
	free(buffer);
}

char	*ft_set_gnl_error(int *error, int value)
{
	if (error)
		*error = value;
	return (NULL);
}

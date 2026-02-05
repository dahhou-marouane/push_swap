/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: one <one@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:58:42 by mdahhou           #+#    #+#             */
/*   Updated: 2026/02/05 16:01:33 by one              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_cw(char *s, char c)
{
	size_t	i;
	size_t	a;

	a = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			a++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (a);
}

static char	*ft_aloword(char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*word;

	start = 0;
	end = 0;
	i = 0;
	if (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
	}
	word = malloc((end - start) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_freei(char **a, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(a[j++]);
	free(a);
	exit(1);
}

void	 ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char *s, char c)
{
	char	**a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	a = malloc(((ft_cw(s, c)) + 1) * sizeof(char *));
	if (!a)
		return (NULL);
	while (i < ft_cw(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		a[i] = ft_aloword(s + j, c);
		if (!a[i])
			ft_freei(a, i);
		j += ft_strlen(a[i]);
		i++;
	}
	a[i] = NULL;
	return (a);
}

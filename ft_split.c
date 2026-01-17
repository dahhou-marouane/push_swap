/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahhou <mdahhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:02:29 by mdahhou           #+#    #+#             */
/*   Updated: 2026/01/17 10:39:23 by mdahhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

size_t	ft_cw(char const *s, char c)
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

static char	*ft_aloword(char const *s, char c)
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

void	*ft_freei(char **a, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(a[j++]);
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
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
			return (ft_freei(a, i));
		j += ft_strlen(a[i]);
		i++;
	}
	a[i] = NULL;
	return (a);
}
int main(int argc, char const *argv[])
{
	int i =0;
	int fd = open("file.txt", O_CREAT | O_RDWR , 0777);
	int d;
	char **a;
	a = ft_split(" 112 000 1234 1 77 77 888 ", ' ');
	while (a[i])
	{
		d = 0;
		while (a[i][d])
		{
			write(fd, &a[i][d], 1);
			d++;
		}
		write(fd, "\n", 1);
		printf("%s\n", a[i]);
		i++;
	}
	close(fd);
	ft_freei(a, i);
}

#include "push_swap_bonus.h"

char	*ft_store_get(char *s, int *error)
{
	char	*p;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	p = malloc(ft_strlen(s) - i + 1);
	if (!p)
	{
		free(s);
		return (ft_set_gnl_error(error, 1));
	}
	p[0] = '\0';
	ft_strlcat_get(p, s + i, ft_strlen(s) - i + 1);
	free(s);
	return (p);
}

char	*ft_line_get(char *s)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	p[0] = '\0';
	ft_strlcat_get(p, s, i + 1);
	return (p);
}

char	*ft_read_buffer_get(int fd, char **store, int *error)
{
	char	*buffer;
	ssize_t	byte;

	byte = 1;
	while (!ft_strchr_get(*store, '\n') && byte > 0)
	{
		buffer = malloc((ssize_t)BUFFER_SIZE + 1);
		if (!buffer)
		{
			ft_free_gnl(store, buffer);
			return (ft_set_gnl_error(error, 1));
		}
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			ft_free_gnl(store, buffer);
			return (ft_set_gnl_error(error, 1));
		}
		buffer[byte] = '\0';
		*store = ft_strjoin_get(*store, buffer);
		free(buffer);
		if (!*store)
			return (ft_set_gnl_error(error, 1));
	}
	return (*store);
}

char	*get_next_line(int fd, int *error)
{
	static char	*store;
	char		*line;

	line = NULL;
	ft_set_gnl_error(error, 0);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_set_gnl_error(error, 1));
	if (!ft_read_buffer_get(fd, &store, error))
		return (NULL);
	if (!store || !*store)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = ft_line_get(store);
	if (!line)
	{
		free(store);
		store = NULL;
		return (ft_set_gnl_error(error, 1));
	}
	store = ft_store_get(store, error);
	return (line);
}

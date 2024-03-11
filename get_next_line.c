/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:12:32 by ctacconi          #+#    #+#             */
/*   Updated: 2024/03/11 20:09:58 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_storage(int fd, char *storage)
{
	ssize_t		bytes_read;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(storage), NULL);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (storage)
				free(storage);
			return (free(buffer), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		storage = ft_strjoin_free(storage, buffer);
		if (!storage || ft_strchr(storage, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *storage)
{
	char		*line;
	size_t		i;

	i = 0;
	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	line = ft_substr(storage, 0, (i + 1));
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	size_t	i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	new_storage = ft_substr(storage, (i + 1), ft_strlen(storage) - i);
	free(storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = update_storage(storage);
	if (!storage)
		return (free(line), NULL);
	if (*storage == '\0')
	{
		free(storage);
		storage = NULL;
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("lines_around_10.txt", O_RDONLY);
	next_line = get_next_line(fd);
	while (next_line)
	{
		printf("[%d]: %s", count, next_line);
		free (next_line);
		next_line = get_next_line(fd);
		count++;
	}
	close (fd);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:12:32 by ctacconi          #+#    #+#             */
/*   Updated: 2024/03/01 23:33:49 by ctacconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//funcion free
/*static char	*free_mallocs()
{
	
	free()
	return (0);
}*/

//funcion que lee y almacena
static char	*fill_storage(int fd, char *storage)
{
	ssize_t		bytes_read;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	/*
		El read puede dar tres cosas:
		-1 si ha habido un error de lectura
		0  si ya he llegado al final del archivo
		o n , si ha leido n bytes
	*/
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// Ha fallado???
		if (bytes_read == -1)
		{
			free(buffer);
			free(storage); // Aqui storage puede ser NULL, o ser un malloc a un string
						   // Pero la funcion free, no peta cuando se le pasa NULL, por lo que me cubre bien ambas posibilidades
			return NULL;
		}
		//Si no ha fallado
		buffer[bytes_read] = '\0';   // <---- esto es muy imporatnte!
		storage = ft_strjoin(storage, buffer);
		//free(buffer);   // <---- esto aqui te hubiera causado seg fault, si no estuvieras leyendo todo de golpe (buffer size 300)
		//buffer = NULL;
		if (ft_strchr(storage, '\n'))
			break ;
	}
	free(buffer);
	return (storage);
}

//funcion que extrae linea
static char	*extract_line(char *storage)
{
	char		*line;
	size_t		i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0' || storage[1] == '\0')
		return (NULL);
	line = ft_substr(storage, (ft_strlen_whit_n_too(storage) - i), (i + 1));
	if (line == NULL)
	{
		//free(line);
		//line = NULL;
		return NULL; 
	}
	line[i + 1] = '\0';
	return (line);
}

//funcion que actualice el storage
static char *update_storage(char *storage)
{
	char	*new_storage;
	size_t		i;

	i = 0;
	//free(new_storage);
	new_storage = NULL;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0' || storage[1] == '\0')
		return (NULL);
	//printf("antes de substr, pondre (i + 1) = %lu, ft_strlen = %zu\n", i + 1, ft_strlen(storage));
	new_storage = ft_substr(storage, (i + 1), ft_strlen(storage));
	//if (*new_storage == '\0')
	//{
	//	free(new_storage);
	//	new_storage = NULL;
	//}
	//new_storage[i + 1] = '\0';	
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*storage;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	storage = fill_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if(!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = update_storage(storage);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("prueba.txt", O_RDONLY);
	next_line = get_next_line(fd);
	while(next_line)
	{
		printf("[%d]: %s\n", count, next_line);
		free (next_line);
		next_line = get_next_line(fd);
		count++;
	}	
	close (fd);
	return (0);
}

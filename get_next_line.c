/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/01 15:49:20 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	 * -1: error -> return NULL
	 * 0: ha terminado de leer el archivo.
	 * ha leido BUFFER_SIZE caracteres
	*/
char	*ft_read_line_file(int fd, char *storage)
{
    char	*buff_datos_leidos;
	int		num_bytes;

	buff_datos_leidos  = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_datos_leidos)
		return (NULL);
	buff_datos_leidos[0] = '\0';

	num_bytes = 1;
/* is no se cumple ft_strchr() == 0
 * si se cumple ft_strchr() == distinto de 0 */
	while(num_bytes > 0 && (!ft_strchr(storage, '\n')))
	{
		/*
		 * read(de donde leo, almaceno lo que leo, cantidad por lectura)
		 */
		num_bytes += read(fd, buff_datos_leidos, BUFFER_SIZE);
		if (num_bytes == -1)
			return NULL;
		else
			storage = ft_strjoin(storage, buff_datos_leidos);
	}	
	buff_datos_leidos[num_bytes] = '\0';
	return storage;
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if(fd < 0 && BUFFER_SIZE <= 0)
		return NULL;
	storage = ft_read_line_file(fd, storage);
	printf("%s\n", storage);
	if(!storage)
		return NULL;
	line = NULL;
	line = ft_extract_line(storage);
	if(!line)
		return NULL;
	storage = ft_update_storage(storage);
	return (line);
}

int	main()
{
	int		fd;
	char	*result;

	result = NULL;
	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opened file");
		return (1);
	}
	printf("%s\n", get_next_line(fd));
	/*
	while (!(result == get_next_line(fd)))
	{
		printf("%s\n", result);
		free(result);
	}*/
	close(fd);
	return (0);
}

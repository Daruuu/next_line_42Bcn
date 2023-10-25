/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/25 23:26:40 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * importante es que read retorna un -1 si hay un error, 
 * si se llega al final de linea retorna un 0 
 * mientras no llegue al final del archivo, regresara los caracteres leidos
 * si hay error return NULl
*/
#include "get_next_line.h"
/*
 * funcion que lee una linea del fd y retorna esa linea a la funcion principal
 * la línea devuelta debe terminar con el caracter \n,
 * excepto si se ha llegado al final del archivo y esté termina con un caracter \0.
*/

/*
 * retorna 0 o 1 si ha encontrado el \0 en el buffer
*/

int	ft_strchr_boolean(char *buffer_datos)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer_datos[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
	/*
	 * -1: error -> return NULL
	 * 0: ha terminado de leer el archivo.
	 * ha leido BUFFER_SIZE caracteres
	*/
char	*ft_read_line_file(int fd, char *storage)
{
    char	*buff_datos_leidos;
	int		num_bits;

	buff_datos_leidos  = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_datos_leidos)
		return (NULL);
	buff_datos_leidos[0] = '\0';
	
	num_bits = 1;
	/*PROBLEMS HERE*/
	while(num_bits > 0 && (!ft_strchr(storage, '\n')))
	{
		num_bits = read(fd, buff_datos_leidos, BUFFER_SIZE);
		if (num_bits == -1)
			return NULL;
		else
			storage = ft_strjoin(storage, buff_datos_leidos);
	}	
	buff_datos_leidos[num_bits] = '\0';
	return storage;
}

char	*get_next_line(int fd)
{
	static char *storage = NULL;
	char *line;

	if(fd < 0 && BUFFER_SIZE <= 0)
		return NULL;
	storage = ft_read_line_file(fd, storage);
	if(!storage)
		return NULL;
	line = ft_extract_line(storage);
	if(!line)
		return NULL;
	storage = update_storage(storage);
	return (line);
}

int	main()
{
	int		fd;
	char	*result;

	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
		return (1);
//	result = ft_readLine_file(fd);
	printf("%s\n", result);

	close(fd);
	return (0);
}

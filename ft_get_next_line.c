/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/18 21:34:04 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * leemos de un file descriptor FD
 * funcion para recorrer una linea y mientras no encuentres un \n no se creara 
 * un malloc de ese size() 
 * cada vez que lleges a un \n habra que imprimir la linea.
 *
 * importante es que read retorna un -1 si hay un error, 
 * si se llega al final de linea retorna un 0 
 * mientras no llegue al final del archivo, regresara los caracteres leidos
 * si hay error return NULl
 */
#include "get_next_line.h"
/*
 * funcion que lee una linea del fd y retorna esa linea a la funcion principal
 *
 * la línea devuelta debe terminar con el caracter \n,
 * excepto si se ha llegado al final del archivo y esté termina con un caracter \0.
*/

/*
char    *ft_readLine_file(int fd)
{
	char    readLine;
	char	*linea_a_leer;
	char	*buff_datos_leidos;
    int     i;
    char    *write_in_ptr;

    write_in_ptr = NULL;
    buff_datos_leidos = NULL;
	if (fd == -1)
		return (NULL);
    linea_a_leer = (char *) malloc(BUFFER_SIZE + 1);
	if (!linea_a_leer || !buff_datos_leidos)
	{
		free(linea_a_leer);
		free(buff_datos_leidos);
		return (NULL);
	}
    readLine = (read(fd, buff_datos_leidos, BUFFER_SIZE) != -1);
    i = 0;
    while (readLine && (buff_datos_leidos != '\0'))
	{
        write_in_ptr[i] = (char) buff_datos_leidos;
        buff_datos_leidos++;
        i++;
    }
	return (buff_datos_leidos);
}
*/
char    *ft_readLine_file(int fd)
{
    char    c;
    char	*linea_a_leer;
    char	*buff_datos_leidos;
    int     i;

    if (fd == -1)
        return (NULL);
	linea_a_leer = malloc((BUFFER_SIZE + 1));

    if (!linea_a_leer)
    {
        free(linea_a_leer);
        return (NULL);
    }
    buff_datos_leidos = linea_a_leer;
    i = 0;
    while ((read(fd, buff_datos_leidos, BUFFER_SIZE) > 0))
    {

        buff_datos_leidos++;
        i++;
    }
    return (buff_datos_leidos);
}

char	*get_next_line(int fd)
{
	char	eo_line;
	char	eo_file;
	char	buffer[1000];
	char	**readfile;
	
	eo_line = '\n';
	eo_file = '\0';

	return (0);
}

int	main()
{
	int		fd;
	char	*result;

	fd = open("fd.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	result = ft_readLine_file(fd);
	printf("%s\n", result);

	close(fd);
	return (0);
}

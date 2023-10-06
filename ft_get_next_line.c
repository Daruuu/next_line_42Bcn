/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 00:44:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/06 22:06:59 by dasalaza         ###   ########.fr       */
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
 *
 */
char	*get_next_line(int fd)
{
	char	eol;
	char	eof;

	eol = '\n';
	eof = '\0';



	return (0);
}

int	main()
{

	return (0);
}

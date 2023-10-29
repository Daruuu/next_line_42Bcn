/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:08:35 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/29 22:20:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char    *ft_free_line(char *str);
int 	ft_strchr_boolean(char *buffer_datos);
char	*ft_readline_file(int fd, char *storage);
char	*ft_strchr(char *str, int c);
char	*ft_extract_line(char *storage);
char	*ft_update_storage(char *storage);

#endif
/*
char *ft_readLine_file(int fd) {
    char *linea_a_leer = (char *)malloc(BUFFER_SIZE + 1);
    if (!linea_a_leer) {
        return NULL;
    }
    char *buff_datos_leidos = linea_a_leer; // Puntero para avanzar en el búfer
    int i = 0;
    char c;

    if (fd == -1) {
        free(linea_a_leer);
        return NULL;
    }

    ssize_t bytes_leidos;

    while ((bytes_leidos = read(fd, &c, 1)) > 0) {
        if (c == '\n' || i >= BUFFER_SIZE) {
            *buff_datos_leidos = '\0';
            break;
        }

        *buff_datos_leidos = c;
        buff_datos_leidos++;
        i++;
    }

    if (bytes_leidos <= 0 && i == 0) {
        free(linea_a_leer);
        return NULL; // No se leyeron datos
    }

    return linea_a_leer;
}
 */

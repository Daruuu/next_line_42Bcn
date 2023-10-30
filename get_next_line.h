/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:08:35 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/30 19:13:54 by dasalaza         ###   ########.fr       */
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

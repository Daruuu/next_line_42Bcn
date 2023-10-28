/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:14 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/28 16:14:04 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * join 2 strings using malloc()
*/
char    *ft_strjoin(char *str1, char *str2)
{
	char	*new_ptr;
	int		i;

	if (!str1 && !str2)
		return (0);
	new_ptr = malloc (sizeof(char) *(ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_ptr)
	{
		free(new_ptr);
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(str1) + ft_strlen(str2))
	{
		if (i < ft_strlen(str1))
			new_ptr[i] = str1[i];
		else
			new_ptr[i] = str2[i - ft_strlen(str1)];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}

/*
 * return length of string
*/
int ft_strlen(char *str)
{
	int i;

    i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
int	ft_strchr_int(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
*/

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (&str[i]);
}

/*
 * esta funcion extrae un string 
 * el STORAGE  
 * extraemos si encontramos un  '/0' en el archivo,
 * cuando tengamos esa longitud
 * rellenamos la LINEA a devolver con el contenido STORAGE
 * hasta la longitud que hemos obtenido en LINE_COPY.
*/

char	*ft_extract_line(char *storage)
{
	char	*line_copy;
	int		size_line;
	char	*line_return;

	line_copy = ft_strchr(storage, '\n');
	size_line = (line_copy - storage) + 1;
//	line_return = ;
	if (!line_return)
		return (NULL);
	return (line_return);
}

char	*ft_free_line(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	size_str;
	size_t			i;

	size_str = ft_strlen(str);
	i = 0;
	if (!str)
		return (NULL);
	if (start > size_str)
		return ("");
	while (str[i] != '\0')
	{


		i++;
	}


	return ();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:14 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/01 19:44:56 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
 * join 2 strings using malloc()
*/
char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_ptr;
	int		i;
	int		j;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		if(str1 == NULL)
			return (0);
		str1[0] = '\0';
	}
	new_ptr = malloc (sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_ptr)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	while (str1[i])
	{
		new_ptr[i] = str1[i];
		i++;
	}
	j = 0;
	while(str2[j])
	{
		new_ptr[i + j] = str2[j];
		j++;
	}
	new_ptr[i + j] = '\0';
	free(str1);
	return (new_ptr);
}

/*
 * return length of string
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
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
	int		size_line;
	char	*line_return;
	int		i;

	/*position_newline = ft_strchr(storage, '\n');
	if (position_newline == NULL)
		return (storage);
	size_line = (position_newline - storage) + 1;
	if(storage[size_line] == '\n')
		size_line++;*/

	i = 0;
	size_line = 0;
	if(storage[0] == '\0')
		return NULL;
	while(storage[size_line] && storage[size_line] != '\n')
		size_line++;
	if(storage[size_line] == '\n')
		size_line++;
	line_return = (char *) malloc((size_line + 1) * sizeof(char));
	if (!line_return)
		return (NULL);
	i = 0;
	while (i < size_line)
	{
		line_return[i] = storage[i];
		i++;
	}
	line_return[i] = '\0';
	return (line_return);
}

char	*ft_free_line(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

/*
char	*ft_update_storage(char *storage)
{
	char	*ptr_newline;
	char	*rest_of_line;
	int		size_rest_of_line;
	int 	i;

	ptr_newline = ft_strchr(storage, '\n') + 1;
	if (!ptr_newline)
		return (NULL);
	size_rest_of_line = 0;
	while (!(ptr_newline[size_rest_of_line] == NULL))
		size_rest_of_line++;
//sumar 1 al malloc si da error
	rest_of_line = (char *) malloc( size_rest_of_line * sizeof(char));
	if (!rest_of_line)
		return (NULL);
	i = 0;
	while (i < size_rest_of_line)
	{
		rest_of_line[i] = ptr_newline[i];
		i++;
	}
	ft_free_line(storage);
	storage = rest_of_line;
	return (storage);
}
*/

char	*ft_update_storage(char *storage)
{
	char	*ptr_newline;
	char	*rest_of_line;
	int		size_rest_of_line;
	int 	i;

	ptr_newline = ft_strchr(storage, '\n');
	if (!ptr_newline)
	{
		free(storage);
		return (NULL);
	}
	size_rest_of_line = ft_strlen(ptr_newline + 1);
	rest_of_line = (char *) malloc( size_rest_of_line * sizeof(char) + 1);
	if (!rest_of_line){
		free(storage);
		return (NULL);
	}
	i = 0;
	while (i < size_rest_of_line)
	{
		rest_of_line[i] = ptr_newline[i + 1];
		i++;
	}
	rest_of_line[i] = '\0';
	ft_free_line(storage);
	storage = rest_of_line;
	return (storage);
}
/*
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
*/

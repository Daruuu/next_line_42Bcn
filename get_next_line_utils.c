/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:37:14 by dasalaza          #+#    #+#             */
/*   Updated: 2023/10/18 13:59:01 by dasalaza         ###   ########.fr       */
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
 * get the length of string
*/
int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
    i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_free_line(char *str)
{
	return (0);

}

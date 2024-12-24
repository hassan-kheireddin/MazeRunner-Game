/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:13:21 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:04:27 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_free(char *s, char *buffer)
{
	char	*temp;

	temp = strjoin(s, buffer);
	free (s);
	return (temp);
}

char	*ft_read(int fd, char *s)
{
	char	*buffer;
	int		check;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (free(buffer), NULL);
		s[0] = '\0';
	}
	check = 1;
	while (!strchr(s, '\n') && check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (free(buffer), free(s), NULL);
		buffer[check] = '\0';
		s = ft_free(s, buffer);
		if (!s)
			return (free(buffer), NULL);
	}
	return (free(buffer), s);
}

char	*get_next_line(int fd)
{
	char		*line1;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line1 = ft_new_line(str);
	str = ft_newstr(str);
	return (line1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:36:12 by hkheired          #+#    #+#             */
/*   Updated: 2024/09/14 10:47:54 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i += 1;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
			dest[i++] = '\0';
	}
	dest[i] = '\0';
	return (dest);
}

char	*f_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}

char	*trim_free(char *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && f_strchr(set, s1[beg]) != NULL)
		beg += 1;
	end = ft_strlen(s1 + beg);
	while (end > beg && strchr(set, s1[(beg + end) - 1]) != NULL)
		end -= 1;
	trimmed_str = malloc((end + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strncpy(trimmed_str, (s1 + beg), end);
	free(s1);
	return (trimmed_str);
}

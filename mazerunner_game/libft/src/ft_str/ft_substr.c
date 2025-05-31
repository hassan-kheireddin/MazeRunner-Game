/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:54:56 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/19 15:16:32 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	char	*cmp_str;
	size_t	new_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	cmp_str = (char *)s + start;
	if (len > ft_strlen(cmp_str))
		new_len = ft_strlen(cmp_str) + 1;
	else
		new_len = len + 1;
	new_str = malloc(new_len * sizeof (char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}

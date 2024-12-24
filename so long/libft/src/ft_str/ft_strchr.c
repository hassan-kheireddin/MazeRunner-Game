/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:43:47 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/18 13:49:46 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (*(s + i) == (char)c)
			return ((char *)s + i);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:10:02 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/19 14:18:58 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s) + 1;
	dup = (char *)malloc(i * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, i);
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 07:57:33 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/21 08:09:54 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{	
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	new_str = (char *)malloc((j + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (i < j)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

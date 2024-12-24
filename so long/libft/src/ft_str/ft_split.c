/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:25:58 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/20 11:35:43 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_countword(const char *s1, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*s1)
	{
		if (*s1 != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*s1 == c)
			check = 0;
		s1++;
	}
	return (i);
}

static char	*ft_dupwords(const char *s2, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = s2[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_dupwords(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

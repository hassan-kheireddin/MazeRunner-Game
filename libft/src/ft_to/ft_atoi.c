/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:07:24 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/19 11:25:31 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	long	sign;
	size_t	i;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == '\v' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return ((int)result * sign);
}

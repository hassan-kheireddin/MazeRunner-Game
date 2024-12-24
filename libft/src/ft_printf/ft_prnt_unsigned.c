/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:22:52 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/25 08:22:57 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_count_unsigndigits(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

void	ft_put_unsigned(unsigned int nbr)
{
	static char	digits[] = "0123456789";

	if (nbr > 9)
		ft_put_unsigned(nbr / 10);
	write(STDOUT_FILENO, &digits[nbr % 10], 1);
}

int	ft_prnt_unsigned(unsigned int nbr)
{
	ft_put_unsigned(nbr);
	return (ft_count_unsigndigits(nbr));
}

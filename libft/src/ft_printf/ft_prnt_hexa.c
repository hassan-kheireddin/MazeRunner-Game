/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:39:38 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/25 08:01:37 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_hexa_countdigit(unsigned int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	ft_put_hexa(unsigned int nbr, bool upper_case)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		ft_put_hexa((nbr / 16), upper_case);
	if (upper_case == true)
		write(STDOUT_FILENO, &upper_digits[nbr % 16], 1);
	else
		write(STDOUT_FILENO, &lower_digits[nbr % 16], 1);
}

int	ft_prnt_hexa(unsigned int nbr, bool upper_case)
{
	ft_put_hexa(nbr, upper_case);
	return (ft_hexa_countdigit(nbr));
}

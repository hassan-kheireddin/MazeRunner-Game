/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 07:58:12 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/25 08:02:59 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_int_countdigits(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits += 1;
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

static void	ft_put_int(int n)
{
	static char	digits[] = "0123456789";

	if (n > 9)
		ft_put_int(n / 10);
	write(STDOUT_FILENO, &digits[n % 10], 1);
}

int	ft_prnt_int(int n)
{
	int	len;

	if (n == INT_MIN)
		return ((write(STDOUT_FILENO, "-2147483648", 11)));
	len = ft_int_countdigits(n);
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n *= -1;
	}
	ft_put_int(n);
	return (len);
}

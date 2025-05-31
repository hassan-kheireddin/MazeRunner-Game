/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:11:25 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/25 08:11:32 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	ft_ptr_countdigits(unsigned long long n)
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

static void	ft_put_ptr(unsigned long long add)
{
	static char	digits[] = "0123456789abcdef";

	if (add >= 16)
		ft_put_ptr(add / 16);
	write(STDOUT_FILENO, &digits[add % 16], 1);
}

int	ft_prnt_ptr(void *add)
{
	if (add == NULL)
		return (write(STDOUT_FILENO, "(nil)", 5));
	write(STDOUT_FILENO, "0x", 2);
	ft_put_ptr((unsigned long long)add);
	return (ft_ptr_countdigits((unsigned long long)add) + 2);
}

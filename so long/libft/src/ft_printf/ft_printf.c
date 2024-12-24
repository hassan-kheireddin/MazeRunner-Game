/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:24:42 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/25 08:24:46 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	exec_conversion(char spec_ltr, va_list args)
{
	if (spec_ltr == '%')
		return (write(1, "%", 1));
	else if (spec_ltr == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (spec_ltr == 's')
		return (ft_prnt_str(va_arg(args, char *)));
	else if (spec_ltr == 'p')
		return (ft_prnt_ptr(va_arg(args, void *)));
	else if (spec_ltr == 'd' || spec_ltr == 'i')
		return (ft_prnt_int(va_arg(args, int)));
	else if (spec_ltr == 'u')
		return (ft_prnt_unsigned(va_arg(args, unsigned int)));
	else if (spec_ltr == 'x')
		return (ft_prnt_hexa(va_arg(args, ssize_t), false));
	else if (spec_ltr == 'X')
		return (ft_prnt_hexa(va_arg(args, ssize_t), true));
	return (0);
}

int	ft_printf(const char *__format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!__format)
		return (0);
	i = 0;
	len = 0;
	va_start(args, __format);
	while (__format[i])
	{
		if (__format[i] == '%')
		{
			i++;
			len += exec_conversion(__format[i], args);
		}
		else
			len += write(1, &__format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

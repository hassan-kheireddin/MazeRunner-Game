/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:54:21 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/28 10:54:25 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

int		ft_printf(const char *__format, ...);
int		ft_prnt_str(char const *str);
int		ft_prnt_ptr(void *ptr_addr);
int		ft_prnt_int(int n);
int		ft_prnt_unsigned(unsigned int nbr);
int		ft_prnt_hexa(unsigned int nbr, bool upper_case);

#endif

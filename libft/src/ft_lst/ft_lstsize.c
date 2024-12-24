/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:23:46 by hkheired          #+#    #+#             */
/*   Updated: 2024/06/21 12:27:15 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list		*temp;
	int			count;

	if (lst == NULL)
		return (0);
	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	return (count);
}

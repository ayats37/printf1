/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:13:31 by taya              #+#    #+#             */
/*   Updated: 2024/11/22 03:29:06 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	count;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = ft_strlen(str);
	ft_putstr(str);
	return (count);
}

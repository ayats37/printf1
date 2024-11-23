/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:49:18 by taya              #+#    #+#             */
/*   Updated: 2024/11/23 03:10:20 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_check_upper_or_lower(unsigned int r, int upper_or_lower)
{
	if (r >= 16)
		return (0);
	if (upper_or_lower == 1)
		return (r + 'A' - 10);
	else
		return (r + 'a' - 10);
}

static char	*ft_cnv_dth(unsigned int n, int upper_or_lower)
{
	char			*str;
	unsigned int	i;
	unsigned int	r;

	i = 0;
	str = malloc(33 * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		r = n % 16;
		if (r < 10)
			str[i++] = r + '0';
		else
			str[i++] = ft_check_upper_or_lower(r, upper_or_lower);
		n = n / 16;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

int	ft_print_hex(unsigned int n, int upper_or_lower)
{
	char	*hex_str;
	int		i;

	i = 0;
	hex_str = ft_cnv_dth(n, upper_or_lower);
	if (!hex_str)
		return (-1);
	while (hex_str[i])
	{
		if (ft_putchar(hex_str[i]) == -1)
		{
			free(hex_str);
			return (-1);
		}
		i++;
	}
	free(hex_str);
	return (i);
}

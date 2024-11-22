/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:49:18 by taya              #+#    #+#             */
/*   Updated: 2024/11/22 03:28:06 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_check_upper_or_lower(unsigned int r, int upper_or_lower)
{
	if (upper_or_lower == 1)
		return (r + 'A' - 10);
	else
		return (r + 'a' - 10);
}

char	*ft_cnv_dth(unsigned int n, int upper_or_lower)
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
	while (hex_str[i])
	{
		ft_putchar(hex_str[i]);
		i++;
	}
	free(hex_str);
	return (i);
}

// int	main(void)
// {
// 	printf("\n%d\n", ft_print_hex(21479889, 0));
// }

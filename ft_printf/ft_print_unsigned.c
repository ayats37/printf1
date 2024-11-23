/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 03:32:52 by taya              #+#    #+#             */
/*   Updated: 2024/11/23 02:36:58 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (n == 0)
	{
		count++;
		if (ft_putchar('0') == -1)
			return (-1);
	}
	else
	{
		nb = n;
		while (nb > 0)
		{
			nb /= 10;
			count++;
		}
		if (ft_putunbr(n) == -1)
			return (-1);
	}
	return (count);
}

// int main()
// {
// 	printf("\n%d\n", ft_print_unsigned(21));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:20:08 by taya              #+#    #+#             */
/*   Updated: 2024/11/22 03:28:24 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int	count;
	int	nb;

	count = 1;
	nb = n;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		nb = -n;
		count++;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	ft_putnbr(n);
	return (count);
}
// int main()
// {
// 	printf("\n%d\n", ft_print_int(0));
// }

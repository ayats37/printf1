/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 03:32:52 by taya              #+#    #+#             */
/*   Updated: 2024/11/22 02:55:52 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = n;
	if (n == 0)
		count++;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	ft_putunbr(n);
	return (count);
}
// int main()
// {
// 	printf("\n%d\n", ft_print_unsigned(21));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:47:04 by taya              #+#    #+#             */
/*   Updated: 2024/11/23 23:08:00 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;
	int	res;

	count = 1;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= 10)
	{
		res = ft_putnbr(n / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int count;
	int res;
	
	count = 1;
	if (n >= 10)
	{
		res = ft_putnbr(n / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	if (ft_putchar((n % 10) + '0') == -1)
		return (-1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}
void	ft_strrev(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
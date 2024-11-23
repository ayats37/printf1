/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:47:04 by taya              #+#    #+#             */
/*   Updated: 2024/11/23 03:10:10 by taya             ###   ########.fr       */
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

	count = 0;
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
	return (count + 1);
}

int	ft_putunbr(unsigned int n)
{
	if (n < 10)
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_putunbr(n / 10) == -1)
			return (-1);
		if (ft_putunbr(n % 10) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
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